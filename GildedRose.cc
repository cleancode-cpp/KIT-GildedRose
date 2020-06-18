#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (auto& item : items)
    {
        if (item.name == "Aged Brie") {
            item.sellIn -= 1;
            item.quality += item.sellIn < 0 ? 2 : 1;
        }
        else if (item.name == "Sulfuras, Hand of Ragnaros") {
            continue;
        }
        else if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
            item.sellIn -= 1;
            item.quality += [&] {
                if (item.sellIn < 0) return -item.quality;
                if (item.sellIn < 5) return +3;
                if (item.sellIn < 10) return +2;
                return +1;
            }();
        }
        else if (item.name == "Conjured Mana Cake") {
            auto c = ConjuredItem::nextSellInQuality({item.sellIn, item.quality});
            item.sellIn = c.sellIn;
            item.quality = c.quality;
        }
        else {
            item.sellIn -= 1;
            item.quality -= item.sellIn < 0 ? 2 : 1;
        }
        if (item.quality < 0) item.quality = 0;
        if (item.quality > 50) item.quality = 50;
        continue;
    }
}
