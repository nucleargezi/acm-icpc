<div id="chart" style="width: 600px; height: 400px;"></div>
<script src="https://cdn.jsdelivr.net/npm/echarts@5.4.3/dist/echarts.min.js"></script>
<script>
const chartDom = document.getElementById('chart');
const myChart = echarts.init(chartDom);
const option = {
    title: { text: '各平台题目数量统计' },
    xAxis: { type: 'category', data: ['atcoder', 'codeforces', 'luogu', 'Prov', 'Regional', 'problemset', 'YUKIcoder', 'Library_chacker', 'BJTU_training'] },
    yAxis: { type: 'value' },
    series: [{ 
        type: 'bar',
        data: [675, 385, 42, 61, 27, 119, 1, 3, 36],
        itemStyle: { color: '#5470c6' },
        label: { show: true, position: 'top' }
    }]
};
myChart.setOption(option);
</script>


#### Summary (since 2024/12)
- 2025/03/15   problems: 1348;   R_lines: 45743;
- 2025/02/28   problems: 1096;   R_lines: 38213;
- 2025/01/30   problems: 833;   R_lines: 30520;
- 2024/12/31   problems: 485;   R_lines: 20786;
#### History (since 2025/03/12)
- 2025/03/15
  - 1366 edu89 -ak
  - 1359 edu88 -ak
  - 1354 edu87 -ak
- 2025/03/14
  - 03-14 2025BJTU个人训练赛(5) Div III -ak
  - 1342 edu86 -F
- 2025/03/13
  - 1334 edu85 -ak
  - 1327 edu84 -G
  - 105385 2024 山东邀请赛
- 2025/03/12
  - 1312 edu83 -F
  - 2074 cf1009 div(3) -ak
  - 1303 edu82 -G