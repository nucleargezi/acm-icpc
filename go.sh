python3 gen_json.py
python3 gen_chart.py
python3 update_stats.py
cat Z_pack/chart.md Z_pack/z_txt0 Z_pack/z_txt2.md > README.md
echo done

git add . && git commit -m "Ciallo～(∠・ω< )⌒★" && git push