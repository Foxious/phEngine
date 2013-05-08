"""
Created Tuesday May 7 18:53 2013

@author: Toli Carter
"""

import os
import xml.etree.ElementTree as ET
import difflib
import keyword


def find_files(root,search):
    '''
    walk a directory tree and return the files with name substrings matching search
    returns found files as file objects in mode 'r'
    '''
    directory = os.walk(root)
    vc_filters = list()
    for folders in directory:
        filters = [os_file for os_file in folders[2] if os_file.find(search) != -1]
        if len(filters) != 0:
            for vc_filter in filters:
                vc_filters.append(os.path.join(folders[0],vc_filter))
    return vc_filters

def update_xml(xml_file):
    xml_tree = ET.parse(xml_file)
    root = xml_tree.getiterator()
    for elem in root:
        for key in elem.attrib.keys():
            # only update include and exclude keys
            if key == "Include":
                update_xml_path(elem, key, xml_file)
            elif key == "Exclude":
                update_xml_path(elem, key, xml_file)              

def update_xml_path(elem, key, xml_file):
    '''
    updates the data in the tree element with fresh data queryed from disk
    '''
    f_path = elem.attrib[key]
    if f_path.find(".") != -1:
        root = os.path.split(xml_file)[0]
        updated_path = find_path(elem,root,f_path)
        if f_path != updated_path:
            elem.attrib[key] == updated_path
            #print 'updated_path:',updated_path,f_path

def find_path(entry,root,path):
    'either returns the same path or the best matched path if the path has changed'
    if path.find(".") != -1: #this is a guess, since most Included files have an extension
        abs_path = os.path.abspath(os.path.join(root,path))
        abs_root = os.path.abspath(root)
        if os.path.exists(abs_path) == True:
            #print 'no changes:' , path
            return path
        else:
            split_path = os.path.split(path)
            paths = find_files("..\\",split_path[1])
            if len(paths)>1:
                # this is a hack to only find files with src in the path in the src directory
                # will fail on file to filter when file or other 
                _paths = [_path for _path in paths if _path.find('src') != -1]
                matches = difflib.get_close_matches(path,_paths)
                paths = matches
            print 'potential paths:',paths
            #the first path is the best match, lets take that
            return paths[0]

def files_conversion(folder,search):
    for filter_path in find_files(folder,search):
        print filter_path
        update_xml(filter_path)
    
    
if __name__ == "__main__":
    files_conversion("..\\",".filters")
