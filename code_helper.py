#! python3

import os
import re
import sys

problem_description_file = "problem_description.txt"

title = ""

description = ""

class_body = ""

title_sub_pattern = re.compile(r"[(\-),]")

common_header_lines = """
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;
"""

namespace_body_tpl = """
namespace {namespace_name} {{
{class_body}
}}
"""

unit_test_body_tpl = """
TEST({test_name}, CASE_TEST) {{
    using namespace {namespace_name};
    Solution s;
    
    EXPECT_EQ(1, 1);
}}
"""

unit_test_source_file = "UnitTest.cpp"
newest_unit_test_source_file = "NewestUnitTest.cpp"


def read_components_from_file():
    global title
    global description
    global class_body
    with open(problem_description_file, "r", encoding="utf-8") as f:
        reading_class_body = False

        for line in f.readlines():
            if not title:
                title = line
                title = title.rstrip("\n")
                print("%r" % title)

            if line.startswith("class Solution {"):
                reading_class_body = True

            if not reading_class_body:
                description += line
            else:
                class_body += line


def generate_file_name(title_):
    order, name = title_.split(". ")
    order = order.zfill(4)
    name = name.replace(" ", "")
    name = title_sub_pattern.sub("_", name)
    return "include/{0}_{1}.h".format(order, name)


def generate_description_doc(description_):
    padding = " * "
    lines = description_.split("\n")[1:-1]
    lines = [padding + line for line in lines]
    lines.insert(0, "/*")
    lines.append(" */")
    lines.append("\n")
    doc = "\n".join(lines)
    return doc


def generate_include_guards(title_):
    order, name = title_.split(". ")
    order = order.zfill(4)
    name = name.replace(" ", "")
    name = title_sub_pattern.sub("_", name)
    guard = "LEET_CODE_{0}_{1}_H_".format(order, name).upper()
    return ["#ifndef {0}\n".format(guard),
            "#define {0}\n".format(guard),
            "#endif //{0}\n".format(guard)]


def generate_source_code_body(title_):
    order, name = title_.split(". ")
    order = order.zfill(4)
    namespace_name = "L{0}".format(order)
    namespace_body = namespace_body_tpl.format(namespace_name=namespace_name, class_body=class_body)

    test_name = "L{0}_{1}".format(order, name)
    test_name = test_name.replace(" ", "")
    test_name = title_sub_pattern.sub("_", test_name)
    unit_test_body = unit_test_body_tpl.format(test_name=test_name, namespace_name=namespace_name)

    source_code_body = namespace_body + unit_test_body + "\n"
    return source_code_body


def update_unittest_file(problem_template_file):
    with open(unit_test_source_file, "r", encoding="utf-8") as f:
        include_statements = f.readlines()

    with open(unit_test_source_file, "w", encoding="utf-8") as f:
        include_file_name = problem_template_file.split("/")[-1]
        include_file_statement = "#include \"{0}\"\n".format(include_file_name)
        include_statements.append(include_file_statement)
        include_statements = sorted(set(include_statements))
        for statement in include_statements:
            f.write(statement)


def update_newest_unittest_file(problem_template_file):
    with open(newest_unit_test_source_file, "w", encoding="utf-8") as f:
        include_file_name = problem_template_file.split("/")[-1]
        include_file_statement = "#include \"{0}\"\n".format(include_file_name)
        f.write(include_file_statement)


def generate_problem_template():
    file_name = generate_file_name(title)
    include_guards = generate_include_guards(title)
    description_doc = generate_description_doc(description)
    source_code_body = generate_source_code_body(title)

    if not os.path.exists(file_name):
        with open(file_name, "w", encoding="utf-8") as f:
            f.write(description_doc)
            f.write(include_guards[0])
            f.write(include_guards[1])
            f.write(common_header_lines)
            f.write(source_code_body)
            f.write(include_guards[2])

    return file_name


def commit_problem_solution():
    solution_file = generate_file_name(title)
    os.system("git add {0}".format(solution_file))
    os.system("git add UnitTest.cpp")
    os.system("git add NewestUnitTest.cpp")
    solution_title = "".join(title.split(" ")[1:])
    commit_message = "new(solution): {0}".format(solution_title)
    os.system("git commit -m \"{0}\"".format(commit_message))


if __name__ == '__main__':
    read_components_from_file()
    if len(sys.argv) == 1 or sys.argv[1] == "generate":
        template_file_name = generate_problem_template()
        update_unittest_file(template_file_name)
        update_newest_unittest_file(template_file_name)
    elif sys.argv[1] == "commit":
        commit_problem_solution()
    else:
        print("generate or commit")
