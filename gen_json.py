import os
import json
from collections import OrderedDict

def f_count(root='.'):
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
        'problemset',
        'ucup'
    ]
    count = OrderedDict()
    
    for oj_name in oj_list:
        path = os.path.join(root, oj_name)
        s = 0
        
        if os.path.isdir(path):
            for rt, st, file_list in os.walk(path):
                for name in file_list:
                    if name.lower().endswith(('.cpp', '.py')):
                        s += 1
        count[oj_name] = s
    
    return count

def update_json(out_path='Z_pack/summary.json'):
    date = f_count()
    with open(out_path, 'w', encoding='utf-8') as f:
        json.dump(date, f, indent=4, ensure_ascii=False)
        
    print("各OJ题目统计结果：")
    for oj, cnt in date.items():
        print(f"{oj}: {cnt}")

if __name__ == "__main__":
    print("counting...")
    update_json()
    print("\nfinished,path: Z_pack/summary.json")