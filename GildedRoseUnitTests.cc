#include <gtest/gtest.h>

#include "GildedRose.h"

#include <sstream>

std::ostream& operator<<(std::ostream& s, Item& item)
{
    s << item.name << ", " << item.sellIn << ", " << item.quality;
    return s;
}

std::ostream& operator<<(std::ostream& s, const SellInQuality& item)
{
    return s << item.sellIn << ", " << item.quality;
}

TEST(GildedRoseTest, ConjuredItem_PositiveSellIn) {
    EXPECT_EQ((SellInQuality{1, 8}), //
        ConjuredItem::nextSellInQuality(SellInQuality{2, 10}));
}
TEST(GildedRoseTest, ConjuredItem_NegativeSellIn) {
    EXPECT_EQ((SellInQuality{-2, 6}), //
        ConjuredItem::nextSellInQuality(SellInQuality{-1, 10}));
}

TEST(GildedRoseTest, ConjuredItem_QualityZero) {
    EXPECT_EQ((SellInQuality{1, 0}), //
        ConjuredItem::nextSellInQuality(SellInQuality{2, 0}));
}


// TEST(GildedRoseLegacyTest, Text) {
//     std::vector<Item> items;
//     items.push_back(Item("Conjured Mana Cake", 3, 6));
//     GildedRose app(items);
//     app.updateQuality();
//     ASSERT_EQ(items[0].quality, 4);
//     ASSERT_EQ(items[0].sellIn, 3);
// }

TEST(GildedRoseLegacyTest, Text) {
    std::vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 49));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 49));
    // this Conjured item doesn't yet work properly
    // items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);

    auto cout = std::stringstream{};
    cout << "OMGHAI!" << endl;

    for (int day = 0; day <= 30; day++)
    {
        cout << "-------- day " << day << " --------" << endl;
        cout << "name, sellIn, quality" << endl;
        for (vector<Item>::iterator i = items.begin(); i != items.end(); i++)
        {
            cout << *i << endl;
        }
        cout << endl;

        app.updateQuality();
    }

    auto expected = [](){
        return R"(OMGHAI!
-------- day 0 --------
name, sellIn, quality
+5 Dexterity Vest, 10, 20
Aged Brie, 2, 0
Elixir of the Mongoose, 5, 7
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 15, 20
Backstage passes to a TAFKAL80ETC concert, 10, 49
Backstage passes to a TAFKAL80ETC concert, 5, 49

-------- day 1 --------
name, sellIn, quality
+5 Dexterity Vest, 9, 19
Aged Brie, 1, 1
Elixir of the Mongoose, 4, 6
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 14, 21
Backstage passes to a TAFKAL80ETC concert, 9, 50
Backstage passes to a TAFKAL80ETC concert, 4, 50

-------- day 2 --------
name, sellIn, quality
+5 Dexterity Vest, 8, 18
Aged Brie, 0, 2
Elixir of the Mongoose, 3, 5
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 13, 22
Backstage passes to a TAFKAL80ETC concert, 8, 50
Backstage passes to a TAFKAL80ETC concert, 3, 50

-------- day 3 --------
name, sellIn, quality
+5 Dexterity Vest, 7, 17
Aged Brie, -1, 4
Elixir of the Mongoose, 2, 4
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 12, 23
Backstage passes to a TAFKAL80ETC concert, 7, 50
Backstage passes to a TAFKAL80ETC concert, 2, 50

-------- day 4 --------
name, sellIn, quality
+5 Dexterity Vest, 6, 16
Aged Brie, -2, 6
Elixir of the Mongoose, 1, 3
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 11, 24
Backstage passes to a TAFKAL80ETC concert, 6, 50
Backstage passes to a TAFKAL80ETC concert, 1, 50

-------- day 5 --------
name, sellIn, quality
+5 Dexterity Vest, 5, 15
Aged Brie, -3, 8
Elixir of the Mongoose, 0, 2
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 10, 25
Backstage passes to a TAFKAL80ETC concert, 5, 50
Backstage passes to a TAFKAL80ETC concert, 0, 50

-------- day 6 --------
name, sellIn, quality
+5 Dexterity Vest, 4, 14
Aged Brie, -4, 10
Elixir of the Mongoose, -1, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 9, 27
Backstage passes to a TAFKAL80ETC concert, 4, 50
Backstage passes to a TAFKAL80ETC concert, -1, 0

-------- day 7 --------
name, sellIn, quality
+5 Dexterity Vest, 3, 13
Aged Brie, -5, 12
Elixir of the Mongoose, -2, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 8, 29
Backstage passes to a TAFKAL80ETC concert, 3, 50
Backstage passes to a TAFKAL80ETC concert, -2, 0

-------- day 8 --------
name, sellIn, quality
+5 Dexterity Vest, 2, 12
Aged Brie, -6, 14
Elixir of the Mongoose, -3, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 7, 31
Backstage passes to a TAFKAL80ETC concert, 2, 50
Backstage passes to a TAFKAL80ETC concert, -3, 0

-------- day 9 --------
name, sellIn, quality
+5 Dexterity Vest, 1, 11
Aged Brie, -7, 16
Elixir of the Mongoose, -4, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 6, 33
Backstage passes to a TAFKAL80ETC concert, 1, 50
Backstage passes to a TAFKAL80ETC concert, -4, 0

-------- day 10 --------
name, sellIn, quality
+5 Dexterity Vest, 0, 10
Aged Brie, -8, 18
Elixir of the Mongoose, -5, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 5, 35
Backstage passes to a TAFKAL80ETC concert, 0, 50
Backstage passes to a TAFKAL80ETC concert, -5, 0

-------- day 11 --------
name, sellIn, quality
+5 Dexterity Vest, -1, 8
Aged Brie, -9, 20
Elixir of the Mongoose, -6, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 4, 38
Backstage passes to a TAFKAL80ETC concert, -1, 0
Backstage passes to a TAFKAL80ETC concert, -6, 0

-------- day 12 --------
name, sellIn, quality
+5 Dexterity Vest, -2, 6
Aged Brie, -10, 22
Elixir of the Mongoose, -7, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 3, 41
Backstage passes to a TAFKAL80ETC concert, -2, 0
Backstage passes to a TAFKAL80ETC concert, -7, 0

-------- day 13 --------
name, sellIn, quality
+5 Dexterity Vest, -3, 4
Aged Brie, -11, 24
Elixir of the Mongoose, -8, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 2, 44
Backstage passes to a TAFKAL80ETC concert, -3, 0
Backstage passes to a TAFKAL80ETC concert, -8, 0

-------- day 14 --------
name, sellIn, quality
+5 Dexterity Vest, -4, 2
Aged Brie, -12, 26
Elixir of the Mongoose, -9, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 1, 47
Backstage passes to a TAFKAL80ETC concert, -4, 0
Backstage passes to a TAFKAL80ETC concert, -9, 0

-------- day 15 --------
name, sellIn, quality
+5 Dexterity Vest, -5, 0
Aged Brie, -13, 28
Elixir of the Mongoose, -10, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, 0, 50
Backstage passes to a TAFKAL80ETC concert, -5, 0
Backstage passes to a TAFKAL80ETC concert, -10, 0

-------- day 16 --------
name, sellIn, quality
+5 Dexterity Vest, -6, 0
Aged Brie, -14, 30
Elixir of the Mongoose, -11, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -1, 0
Backstage passes to a TAFKAL80ETC concert, -6, 0
Backstage passes to a TAFKAL80ETC concert, -11, 0

-------- day 17 --------
name, sellIn, quality
+5 Dexterity Vest, -7, 0
Aged Brie, -15, 32
Elixir of the Mongoose, -12, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -2, 0
Backstage passes to a TAFKAL80ETC concert, -7, 0
Backstage passes to a TAFKAL80ETC concert, -12, 0

-------- day 18 --------
name, sellIn, quality
+5 Dexterity Vest, -8, 0
Aged Brie, -16, 34
Elixir of the Mongoose, -13, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -3, 0
Backstage passes to a TAFKAL80ETC concert, -8, 0
Backstage passes to a TAFKAL80ETC concert, -13, 0

-------- day 19 --------
name, sellIn, quality
+5 Dexterity Vest, -9, 0
Aged Brie, -17, 36
Elixir of the Mongoose, -14, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -4, 0
Backstage passes to a TAFKAL80ETC concert, -9, 0
Backstage passes to a TAFKAL80ETC concert, -14, 0

-------- day 20 --------
name, sellIn, quality
+5 Dexterity Vest, -10, 0
Aged Brie, -18, 38
Elixir of the Mongoose, -15, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -5, 0
Backstage passes to a TAFKAL80ETC concert, -10, 0
Backstage passes to a TAFKAL80ETC concert, -15, 0

-------- day 21 --------
name, sellIn, quality
+5 Dexterity Vest, -11, 0
Aged Brie, -19, 40
Elixir of the Mongoose, -16, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -6, 0
Backstage passes to a TAFKAL80ETC concert, -11, 0
Backstage passes to a TAFKAL80ETC concert, -16, 0

-------- day 22 --------
name, sellIn, quality
+5 Dexterity Vest, -12, 0
Aged Brie, -20, 42
Elixir of the Mongoose, -17, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -7, 0
Backstage passes to a TAFKAL80ETC concert, -12, 0
Backstage passes to a TAFKAL80ETC concert, -17, 0

-------- day 23 --------
name, sellIn, quality
+5 Dexterity Vest, -13, 0
Aged Brie, -21, 44
Elixir of the Mongoose, -18, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -8, 0
Backstage passes to a TAFKAL80ETC concert, -13, 0
Backstage passes to a TAFKAL80ETC concert, -18, 0

-------- day 24 --------
name, sellIn, quality
+5 Dexterity Vest, -14, 0
Aged Brie, -22, 46
Elixir of the Mongoose, -19, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -9, 0
Backstage passes to a TAFKAL80ETC concert, -14, 0
Backstage passes to a TAFKAL80ETC concert, -19, 0

-------- day 25 --------
name, sellIn, quality
+5 Dexterity Vest, -15, 0
Aged Brie, -23, 48
Elixir of the Mongoose, -20, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -10, 0
Backstage passes to a TAFKAL80ETC concert, -15, 0
Backstage passes to a TAFKAL80ETC concert, -20, 0

-------- day 26 --------
name, sellIn, quality
+5 Dexterity Vest, -16, 0
Aged Brie, -24, 50
Elixir of the Mongoose, -21, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -11, 0
Backstage passes to a TAFKAL80ETC concert, -16, 0
Backstage passes to a TAFKAL80ETC concert, -21, 0

-------- day 27 --------
name, sellIn, quality
+5 Dexterity Vest, -17, 0
Aged Brie, -25, 50
Elixir of the Mongoose, -22, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -12, 0
Backstage passes to a TAFKAL80ETC concert, -17, 0
Backstage passes to a TAFKAL80ETC concert, -22, 0

-------- day 28 --------
name, sellIn, quality
+5 Dexterity Vest, -18, 0
Aged Brie, -26, 50
Elixir of the Mongoose, -23, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -13, 0
Backstage passes to a TAFKAL80ETC concert, -18, 0
Backstage passes to a TAFKAL80ETC concert, -23, 0

-------- day 29 --------
name, sellIn, quality
+5 Dexterity Vest, -19, 0
Aged Brie, -27, 50
Elixir of the Mongoose, -24, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -14, 0
Backstage passes to a TAFKAL80ETC concert, -19, 0
Backstage passes to a TAFKAL80ETC concert, -24, 0

-------- day 30 --------
name, sellIn, quality
+5 Dexterity Vest, -20, 0
Aged Brie, -28, 50
Elixir of the Mongoose, -25, 0
Sulfuras, Hand of Ragnaros, 0, 80
Sulfuras, Hand of Ragnaros, -1, 80
Backstage passes to a TAFKAL80ETC concert, -15, 0
Backstage passes to a TAFKAL80ETC concert, -20, 0
Backstage passes to a TAFKAL80ETC concert, -25, 0

)";
    }();

    EXPECT_EQ(cout.str(), expected);
}

void example()
{
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    app.updateQuality();
}
