import json
import matplotlib.pyplot as plt
import os

def generate_oj_chart(json_path='Z_pack/summary.json', output_path='Z_pack/chart.png'):
    # Validate and load data
    if not os.path.exists(json_path):
        raise FileNotFoundError(f"Error: Statistics file {json_path} not found")

    with open(json_path, 'r', encoding='utf-8') as f:
        oj_data = json.load(f)

    # Prepare chart data
    platforms = list(oj_data.keys())
    problem_counts = list(oj_data.values())

    # Create figure
    fig, ax = plt.subplots(figsize=(14, 7))
    bars = ax.bar(platforms, problem_counts, color='#FFC0CB', 
                 edgecolor='white', linewidth=0.7)

    # Add value labels
    for bar in bars:
        height = bar.get_height()
        ax.text(bar.get_x() + bar.get_width()/2., height + 5,
                f'{height}',
                ha='center', va='bottom', fontsize=10)

    # Customize appearance
    ax.set_title('Programming Platform Problem Statistics', fontsize=16, pad=20)
    ax.set_xlabel('Platforms', fontsize=12)
    ax.set_ylabel('Problems Count', fontsize=12)
    ax.set_ylim(0, max(problem_counts) * 1.15)  # Auto-scale Y-axis
    ax.grid(axis='y', linestyle='--', alpha=0.4)
    
    # Rotate X-axis labels
    plt.xticks(rotation=45, ha='right', rotation_mode='anchor')

    # Save output
    plt.tight_layout()
    plt.savefig(output_path, dpi=300, bbox_inches='tight', transparent=False)
    print(f"Chart generated: {os.path.abspath(output_path)}")

if __name__ == "__main__":
    print("waiting...")
    try:
        generate_oj_chart()
        print("Chart generated successfully!")
    except Exception as e:
        print(f"Error: {str(e)}")