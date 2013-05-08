"""
Created Tuesday May 7 18:53 2013

@author: Toli Carter
"""

import os
import xml.etree.ElementTree as ET

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
                vc_filters.append(folders[0] + '\\'+ vc_filter)
    print vc_filters
    return vc_filters

def parse_xml(xml_file):
    xml_tree = ET.parse(xml_file)
    root = xml_tree.getiterator()
    for x in root:
        print 'attr: ',,'\ntext: ', x.text

def files_conversion(folder,search):
    for filter_path in find_files(folder,search):
        print filter_path
        parse_xml(filter_path)
    
    
if __name__ == "__main__":
    files_conversion("..\\",".filters")
