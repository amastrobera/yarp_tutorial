#! /usr/bin/python

from os import path
from subprocess import call
from sys import exit
import xml.etree.ElementTree as ET


def rec_print_child(root, space=""):
    if len(list(root)) == 0:
        print space + root.tag + ": " + root.text
    else:
        for child in root:
            rec_print_child(child, space + "  ")

package_path = path.dirname(__file__)
package_file = path.join(package_path, 'package.xml')

tree = ET.parse(package_file)
root = tree.getroot()

print "========= build.py ========="
# 0. this is only a sanity check of the program (todo: remove)
print "opening " + package_file
rec_print_child(root)

# 1. variable check. exit on variable not found
rel_build_dir = root.find('build_dir')
if rel_build_dir == None:
    print "missing build_dir"
    exit(1)

# 2. writing a CMakeList (todo: write it)

# 3. launch a build
build_dir = path.join(package_path, rel_build_dir.text)
print "build_dir: " + build_dir
#call(["mkdir", build_dir])
#call(["cmake", ".."])
#call(["make", "-C", build_dir, "-j", "4"])
