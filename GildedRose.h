#include <string>
#include <vector>

using namespace std;

struct SellInQuality {
    int sellIn;
    int quality;

    bool operator== (const SellInQuality& r) const {
        return sellIn == r.sellIn && quality == r.quality;
    }
};

class ConjuredItem
{
public:
    static auto nextSellInQuality(SellInQuality s) -> SellInQuality {
        //
        return {};
    }
};

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
};

