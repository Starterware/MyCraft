package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

public class GetBetterWithTimeUpdateStrategy extends DefaultUpdateStrategy {
    public static final int MAX_QUALITY = 50;

    @Override
    public void updateQuality(Item item) {
        item.quality += (item.sellIn < 0) ? 2 : 1;
        if (item.quality > MAX_QUALITY)
            item.quality = MAX_QUALITY;
    }
}
