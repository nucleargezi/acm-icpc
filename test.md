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
