import matplotlib.pyplot as plt
import matplotlib.patches as patches

# Створення фігури з високим розділенням (DPI)
fig, ax = plt.subplots(figsize=(10, 6.2), dpi=300)

# Темний графітовий фон у стилі сучасних IT-інтерфейсів / Dashboard
bg_color = '#0F172A'
fig.patch.set_facecolor(bg_color)
ax.set_facecolor(bg_color)

# Дані 4-х блоків: (Текст, Номер, Акцентний неоновий колір)
cards_data = [
    ("Автономний блок\nгенерації (LFSR)", "01", "#38BDF8"),  # Неоново-блакитний
    ("Блок динамічних\nпобітових операцій", "02", "#A855F7"),  # Електрик-фіолетовий
    ("Блок безпечної\nпередачі даних", "03", "#34D399"),  # Смарагдовий
    ("Блок криптографічного\nзнищення даних", "04", "#FB7185")  # Неоново-рожевий
]

# Координати для сітки 2х2
positions = [
    (0.6, 3.2),  # Блок 1 (Верхній лівий)
    (5.2, 3.2),  # Блок 2 (Верхній правий)
    (0.6, 1.1),  # Блок 3 (Нижній лівий)
    (5.2, 1.1)  # Блок 4 (Нижній правий)
]

card_w = 4.2
card_h = 1.8

for (title, num, color), (x, y) in zip(cards_data, positions):
    # 1. Ефект м'якого неонового світіння заднього фону (Glow Effect)
    glow = patches.FancyBboxPatch(
        (x - 0.04, y - 0.04), card_w + 0.08, card_h + 0.08,
        boxstyle="round,pad=0.05,rounding_size=0.15",
        facecolor=color,
        edgecolor='none',
        alpha=0.15,
        zorder=1
    )
    ax.add_patch(glow)

    # 2. Основна плашка (Темна картка з кольоровою рамкою)
    card = patches.FancyBboxPatch(
        (x, y), card_w, card_h,
        boxstyle="round,pad=0.08,rounding_size=0.15",
        linewidth=1.2,
        edgecolor=color,
        facecolor='#1E293B',  # Темно-синій Slate
        zorder=2
    )
    ax.add_patch(card)

    # 3. Вертикальна акцентна смужка зліва
    accent_bar = patches.FancyBboxPatch(
        (x + 0.18, y + 0.25), 0.08, card_h - 0.5,
        boxstyle="round,pad=0.01,rounding_size=0.03",
        facecolor=color,
        edgecolor='none',
        zorder=3
    )
    ax.add_patch(accent_bar)

    # 4. Бейдж з номером блоку у верхньому правому кутку
    ax.text(
        x + card_w - 0.35, y + card_h - 0.3,
        f"#{num}",
        color=color,
        fontsize=12,
        fontweight='bold',
        ha='right', va='top',
        alpha=0.9,
        zorder=3
    )

    # 5. Текст назви блоку
    ax.text(
        x + 0.45, y + (card_h / 2),
        title,
        color='#F8FAFC',
        fontsize=11,
        fontweight='bold',
        linespacing=1.35,
        ha='left', va='center',
        zorder=3
    )

# Стильний підпис під рисунком
ax.text(
    5.0, 0.35,
    "Рис. 4. Перевірка додатково введених блоків",
    color='#94A3B8',
    fontsize=12,
    fontweight='medium',
    ha='center', va='center'
)

# Налаштування меж та вимкнення осі
ax.set_xlim(0, 10)
ax.set_ylim(0, 5.4)
ax.axis('off')

plt.tight_layout()

# Збереження зображення
output_file = 'ris_4_tech_style.png'
plt.savefig(output_file, dpi=300, bbox_inches='tight', facecolor=fig.get_facecolor())
plt.show()

print(f"Ультрастильну схему успішно збережено у файл: {output_file}")
