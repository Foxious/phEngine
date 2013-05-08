"""
Created Tuesday May 7 18:53 2013

@author: Toli Carter
"""

import os
import xml.etree.ElementTree as ET

def find_filters(root):
    directory = os.walk(root)
    filters = list()
    for folders in directory:
        for files in folders[2]:
            filters = [vc_filter for vc_filter in files if vc_filter.split("filter") > 1]


if __name__ == "__main__":
    find_filters("../")
