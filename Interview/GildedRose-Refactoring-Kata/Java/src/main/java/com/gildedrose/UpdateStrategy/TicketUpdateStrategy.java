package com.gildedrose.UpdateStrategy;

import com.gildedrose.Item;

public class TicketUpdateStrategy extends DefaultUpdateStrategy {
    public static final int MAX_QUALITY = 50;
    public static final int DOUBLE_INCREASE_DAYS = 10;
    public static final int TRIPLE_INCREASE_DAYS = 5;

    @Override
    public void updateQuality(Item item) {
        if (sellDateHasPassed(item)) {
            setQualityToWorthless(item);
        } else {
            increaseQuality(item);
        }
    }

    private void setQualityToWorthless(Item item) {
        item.quality = 0;
    }

    private void increaseQuality(Item item) {
        if (reachedDoubleIncreaseDate(item)) {
            item.quality += reachedTripleIncreaseDate(item) ? 3 : 2;
        } else {
            item.quality++;
        }

        if (item.quality > MAX_QUALITY)
            item.quality = MAX_QUALITY;
    }

    public boolean reachedDoubleIncreaseDate(Item item) {
        return item.sellIn < DOUBLE_INCREASE_DAYS;
    }

    public boolean reachedTripleIncreaseDate(Item item) {
        return item.sellIn < TRIPLE_INCREASE_DAYS;
    }
}
