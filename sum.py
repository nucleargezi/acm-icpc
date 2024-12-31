import os

def count_cpp_files(directory):
    cpp_count = 0
    for root, _, files in os.walk(directory):
        cpp_count += sum(1 for file in files if file.endswith('.cpp'))
    return cpp_count

if __name__ == "__main__":
    current_directory = os.getcwd()  # 获取当前文件夹路径
    cpp_file_count = count_cpp_files(current_directory)
    print(f"cnt = {cpp_file_count}")
    print(70436 - cpp_file_count * 90)