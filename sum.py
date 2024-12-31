import os
import re
from datetime import datetime

def count_cpp_files(directory):
    cpp_count = -1
    for root, _, files in os.walk(directory):
        cpp_count += sum(1 for file in files if file.endswith('.cpp') or file.endswith('.py'))
    return cpp_count

def count_cpp_lines(directory):
    # 定义正则表达式
    include_pattern = re.compile(r"^\s*#include.*")
    macro_pattern = re.compile(r"^\s*#define.*")
    conditional_pattern = re.compile(r"^\s*#(if|ifdef|ifndef|endif|else|elif).*")
    main_func_pattern = re.compile(r"\bmain\b")
    before_func_pattern = re.compile(r"\bbefore\b")
    pre_work_func_pattern = re.compile(r"\bpre_work\b")
    comment_pattern = re.compile(r"^\s*(//.*|/\*.*\*/|/\*.*|.*\*/)$")

    total_lines = 0
    for root, _, files in os.walk(directory):
        for file in files:
            if file == 'sum.py':
                continue
            if file.endswith(".cpp"):
                file_path = os.path.join(root, file)
                with open(file_path, 'r', encoding='utf-8') as f:
                    in_main_func = False
                    in_before_func = False
                    in_pre = False
                    in_multiline_comment = False
                    in_def = False
                    for line in f:
                        stripped_line = line.strip()

                        # 跳过空行
                        if not stripped_line:
                            continue
                        # 处理多行注释
                        if stripped_line.startswith("/*"):
                            in_multiline_comment = True
                        if in_multiline_comment:
                            if stripped_line.endswith("*/"):
                                in_multiline_comment = False
                            continue

                        # 跳过注释
                        if comment_pattern.match(stripped_line):
                            continue
                        # 跳过头文件、宏定义和条件编译
                        if (include_pattern.match(stripped_line) or macro_pattern.match(stripped_line)):
                            continue
                        
                        if (conditional_pattern.match(stripped_line)): 
                            in_def = True
                            continue
                        if in_def: 
                            if (conditional_pattern.match(stripped_line)):
                                in_def = False
                            continue
                        # 检查 main 函数和 before 函数
                        if main_func_pattern.search(stripped_line):
                            in_main_func = True
                        if before_func_pattern.search(stripped_line):
                            in_before_func = True
                        if pre_work_func_pattern.search(stripped_line):
                            in_pre = True
                        # 跳过 main 函数和 before 函数中的内容
                        if in_main_func or in_before_func or in_pre:
                            if '}' in stripped_line:  # 函数结束
                                in_main_func = False
                                in_before_func = False
                                in_pre = False
                            continue

                        # 统计有效代码行
                        total_lines += 1
            elif file.endswith(".py"):
                file_path = os.path.join(root, file)
                with open(file_path, 'r', encoding='utf-8') as f:
                    for line in f:
                        stripped_line = line.strip()
                        if not stripped_line:
                            continue
                        total_lines += 1
    return total_lines

if __name__ == "__main__":

    current_date = datetime.now()
    formatted_date = current_date.strftime("%Y/%m/%d")
    current_year_month = formatted_date[:7]

    current_directory = os.getcwd()  # 获取当前文件夹路径
    cpp_file_count = count_cpp_files(current_directory)
    total_cpp_lines = count_cpp_lines(current_directory)

    mess = '##### ' + formatted_date + f"   problems: {cpp_file_count};" + f"   R_lines: {total_cpp_lines};"
    print(mess)

    file_path = "README.md"
    with open(file_path, 'r+', encoding='utf-8') as file:
        # 读取文件内容
        lines = file.readlines()
        
        if lines:  # 文件非空
            first_line = lines[0].strip()  # 去除首行两端空白字符
            first_year_month = first_line[6:13]  # 提取首行年份和月份部分
            if first_year_month == current_year_month:
                # 覆盖第一行
                lines[0] = mess + "\n"
                print("cover")
            else:
                # 插入到第一行
                lines.insert(0, mess + "\n")
                print("insert")
        else:
            # 文件为空，直接写入
            lines = [mess + "\n"]
        
        # 回到文件开头，写入更新后的内容
        file.seek(0)
        file.writelines(lines)
        file.truncate()  # 截断文件，移除多余内容（如果文件变短）