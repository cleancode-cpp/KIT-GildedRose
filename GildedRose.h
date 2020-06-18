#include <string>
#include <vector>

using namespace std;

// struct ItemBase {
//     virtual ~ItemBase() {}
//     virtual auto name() const -> std::string = 0;
//     virtual auto nextSellInQuality() const -> SellInQuality = 0;

// private:
//     SellInQuality m;
// };
// struct ConjuredItem : ItemBase {
//     auto nextSellInQuality() const -> SellInQuality override;
// };

struct SellInQuality {
    int sellIn;
    int quality;

    bool operator== (const SellInQuality& r) const {
        return sellIn == r.sellIn && quality == r.quality;
    }

    auto nextForConjuredItem() const -> SellInQuality;
    auto nextForAgedBrie() const -> SellInQuality;
    auto nextForBackstagePasses() const -> SellInQuality;
    auto nextForRagnaros() const -> SellInQuality;

    static auto nextFor(Item item) -> SellInQuality;
};

class ConjuredItem
{
public:
    static auto nextSellInQuality(SellInQuality s) -> SellInQuality {
        s.sellIn -= 1;
        s.quality += (s.sellIn < 0) ? -4 : -2;
        if (s.quality < 0) s.quality = 0;
        return s;
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

