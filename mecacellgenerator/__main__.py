#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import shutil
import sys
import tools as t
import argparse
from jinja2 import Environment, FileSystemLoader


def main():
    parser = argparse.ArgumentParser(description='Mecacell project generator')
    parser.add_argument("name", help='project name')
    parser.add_argument('-c', '--nocmake', help='don\'t generate CmakeList')
    parser.add_argument('-v', '--noviewer',
                        help='no qt viewer, console code only')
    args = parser.parse_args()
    baseDirectory = os.path.dirname(os.path.abspath(__file__)) + \
        '/templates'
    env = Environment(loader=FileSystemLoader(searchpath=baseDirectory))
    viewerEnabled = True
    if args.noviewer is not None:
        viewerEnabled = False

    if (os.path.exists(args.name)):
        msg = t.colors.WARNING + 'path ' + args.name + \
            ' already exists. ' + t.colors.ENDC + 'Overwrite?'
        if not t.queryYN(msg, 'no'):
            sys.exit()
    else:
        os.makedirs(args.name)

    def mkdir(pname):
        if not os.path.exists(pname):
            os.makedirs(pname)

    with t.cd(args.name):
        projName = args.name.split('/')[-1]
        print t.colors.HEADER, 'Generating project', args.name, t.colors.ENDC
        sys.stdout.write(' * creating project architecture')
        if args.nocmake is None:
            mkdir('bin')
            mkdir('build')
        mkdir('src')
        mkdir('src/core')
        t.OK()
        tmplScenario = t.queryYN(
            'Do you want your scenario to be a class template (with cell type as parameter)?', 'no')
        print 'Name of your scenario class? [default = "Scenario"]',
        scName = raw_input()
        if not scName:
            scName = 'Scenario'
        print 'Name of your cell class? [default = "Cell"]',
        cellName = raw_input()
        if not cellName:
            cellName = 'Cell'
        sys.stdout.write(' * generating base source files')
        with open("src/mainconsole.cpp", "wb") as fh:
                fh.write(env.get_template('mainconsole.cpp').render(
                    tmplScenario=tmplScenario, Scenario=scName, Cell=cellName))
        if viewerEnabled:
            with open("src/mainviewer.cpp", "wb") as fh:
                fh.write(env.get_template('mainviewer.cpp').render(
                    tmplScenario=tmplScenario, Scenario=scName, Cell=cellName))
        with open("src/core/" + cellName.lower() + ".h", "wb") as fh:
                fh.write(env.get_template('cell.h').render(Cell=cellName))
        with open("src/core/" + cellName.lower() + ".cpp", "wb") as fh:
                fh.write(env.get_template('cell.cpp').render(Cell=cellName))
        if tmplScenario:
            with open("src/core/" + scName.lower() + ".hpp", "wb") as fh:
                fh.write(env.get_template('scenario.hpp').render(
                    Scenario=scName, Cell=cellName))
        else:
            with open("src/core/" + scName.lower() + ".h", "wb") as fh:
                fh.write(env.get_template('scenario.h').render(
                    Scenario=scName, Cell=cellName))
            with open("src/core/" + scName.lower() + ".cpp", "wb") as fh:
                fh.write(env.get_template('scenario.cpp').render(
                    Scenario=scName, Cell=cellName))
        t.OK()
        if args.nocmake is None:
            sys.stdout.write(' * generating CMakeLists.txt')
            with open("CMakeLists.txt", "wb") as fh:
                fh.write(env.get_template('CMakeLists.txt').render(
                    Project=projName, viewerEnabled=viewerEnabled))
            t.OK()

if __name__ == "__main__":
    main()
