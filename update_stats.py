import os
from datetime import datetime

def count(root='.'):
    oj_list = [
        'Aizu',
        'atcoder',
        'codeforces',
        'camp_like',
        'luogu',
        'Library_chacker',
        'Loj',
        'qoj',
        'YUKIcoder',
        'BJTU_training',
        'Prov',
        'Regional',
        'problemset'
    ]
    res = 0
    for oj_name in oj_list:
        path = os.path.join(root, oj_name)
        s = 0
        
        if os.path.isdir(path):
            for rt, st, file_list in os.walk(path):
                for name in file_list:
                    if name.lower().endswith(('.cpp', '.py')):
                        s += 1
        res += s
    
    return res

def upd(path='Z_pack/z_txt0'):
    new_t = datetime.now().strftime('%Y/%m/%d')
    new_mo = datetime.now().strftime('%Y/%m')
    new_cnt = count()

    # 读取原有内容
    before = []
    if os.path.exists(path):
        with open(path, 'r', encoding='utf-8') as 文件:
            before = 文件.readlines()

    # 处理内容
    new_doc = []
    head = "#### Summary (since 2024/12)\n"
    
    # 保留头部
    if before and before[0].startswith('********'):
        new_doc.append(before[0])
    else:
        new_doc.append(head)

    # 检查当月是否已有记录
    vis = any(new_mo in Line for Line in before)

    if vis:
        # 更新当月数据
        for Line in before[1:]:  # 跳过头部行
            if Line.startswith('- ') and new_mo in Line:
                new_doc.append(f"- {new_t}   problems: {new_cnt};\n")
            elif Line.strip():
                new_doc.append(Line)
    else:
        # 添加新数据（放在头部行之后）
        new_doc.append(f"- {new_t}   problems: {new_cnt};\n")
        # 保留旧数据
        for Line in before[1:]:  # 跳过头部行
            if Line.startswith('- ') and Line.strip():
                new_doc.append(Line)

    # 写入文件
    with open(path, 'w', encoding='utf-8') as 文件:
        文件.writelines(new_doc)

if __name__ == "__main__":
    cnt = count()
    print(f"当前AC题目总数: {cnt}")
    upd()
    print("Z_pack/z_txt0 文件已更新！")