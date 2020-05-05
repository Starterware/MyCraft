package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

public class TicketUpdateStrategy extends DefaultUpdateStrategy {
    public static final int MAX_QUALITY = 50;
    public static final int DOUBLE_INCREASE_DAYS = 10;
    public static final int TRIPLE_INCREASE_DAYS = 5;

    @Override
    public void updateQuality(Item item) {
        if (item.sellIn < 0) {
            item.quality = 0;
        } else {
            item.quality++;
            if (item.sellIn < DOUBLE_INCREASE_DAYS) {
                item.quality += (item.sellIn < TRIPLE_INCREASE_DAYS) ? 2 : 1;
            }
            if (item.quality > MAX_QUALITY)
                item.quality = MAX_QUALITY;
        }
    }
}
