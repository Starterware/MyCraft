package com.gildedrose;

import com.gildedrose.UpdateStrategy.GetBetterWithTimeUpdateStrategy;
import com.gildedrose.UpdateStrategy.TicketUpdateStrategy;
import org.junit.jupiter.api.Test;

import static com.google.common.truth.Truth.assertThat;

class GildedRoseTest {
    private final String ITEM_NAME = "foo";
    private final String SULFURAS = "Sulfuras, Hand of Ragnaros";
    private final String BACKSTAGE_PASSES = "Backstage passes to a TAFKAL80ETC concert";
    private final String BRIE = "Aged Brie";

    @Test
    void testItemDegrades() {
        int sellIn = 1, quality = 5;
        Item[] items = items(item(ITEM_NAME, sellIn, quality));
        assertContains(updateQuality(items), item(ITEM_NAME, sellIn - 1, quality - 1));
    }

    @Test
    void testItemDegradesTwiceAfterSellDate() {
        int sellIn = 0, quality = 5;
        Item[] items = items(item(ITEM_NAME, sellIn, quality));
        assertContains(updateQuality(items), item(ITEM_NAME, sellIn - 1, quality - 2));
    }

    @Test
    void testItemQualityCannotBeNegative() {
        int sellIn = -1, quality = 0;
        Item[] items = items(item(ITEM_NAME, sellIn, quality));
        assertContains(updateQuality(items), item(ITEM_NAME, sellIn - 1, 0));
    }

    @Test
    void testSulfuraItemsDoNotDegrade() {
        int sellIn = -1, quality = 80;
        Item[] items = items(item(SULFURAS, sellIn, quality));
        assertContains(updateQuality(items), item(SULFURAS, sellIn, quality));
    }

    @Test
    void testBrieIncreaseInQuality() {
        int sellIn = 5, quality = 5;
        Item[] items = items(item(BRIE, sellIn, quality));
        assertContains(updateQuality(items), item(BRIE, sellIn - 1, quality + 1));
    }

    @Test
    void testBrieIncreaseInQualityTwiceAfterSellDate() {
        int sellIn = 0, quality = 5;
        Item[] items = items(item(BRIE, sellIn, quality));
        assertContains(updateQuality(items), item(BRIE, sellIn - 1, quality + 2));
    }

    @Test
    void testBrieQualityIsLimited() {
        int sellIn = 0, quality = GetBetterWithTimeUpdateStrategy.MAX_QUALITY;
        Item[] items = items(item(BRIE, sellIn, quality));
        assertContains(updateQuality(items), item(BRIE, sellIn - 1, GetBetterWithTimeUpdateStrategy.MAX_QUALITY));
    }

    @Test
    void testBackstagePassItemsIncreaseInQuality() {
        int sellIn = 11, quality = 5;
        Item[] items = items(item(BACKSTAGE_PASSES, sellIn, quality));
        assertContains(updateQuality(items), item(BACKSTAGE_PASSES, sellIn - 1, quality + 1));
    }

    @Test
    void testBackstagePassItemsIncreaseInQualityTwiceWhenOnlyTenDaysAreLeft() {
        int sellIn = 10, quality = 5;
        Item[] items = items(item(BACKSTAGE_PASSES, sellIn, quality));
        assertContains(updateQuality(items), item(BACKSTAGE_PASSES, sellIn - 1, quality + 2));
    }

    @Test
    void testBackstagePassItemsIncreaseInQualityTriceWhenOnlyFiveDaysAreLeft() {
        int sellIn = 5, quality = 5;
        Item[] items = items(item(BACKSTAGE_PASSES, sellIn, quality));
        assertContains(updateQuality(items), item(BACKSTAGE_PASSES, sellIn - 1, quality + 3));
    }

    @Test
    void testBackstagePassItemsAreWorthNothingAfterSellDate() {
        int sellIn = 0, quality = 5;
        Item[] items = items(item(BACKSTAGE_PASSES, sellIn, quality));
        assertContains(updateQuality(items), item(BACKSTAGE_PASSES, sellIn - 1, 0));
    }

    @Test
    void testBackstagePassItemsQualityIsLimited() {
        int sellIn = 4, quality = TicketUpdateStrategy.MAX_QUALITY;
        Item[] items = items(item(BACKSTAGE_PASSES, sellIn, quality));
        assertContains(updateQuality(items), item(BACKSTAGE_PASSES, sellIn - 1, TicketUpdateStrategy.MAX_QUALITY));
    }

    @Test
    void testHandlesMultipleItems() {
        Item[] items = items(
                item(ITEM_NAME, 3, 4),
                item(BACKSTAGE_PASSES, 16, 7));
        assertContains(updateQuality(items),
                item(ITEM_NAME, 2, 3),
                item(BACKSTAGE_PASSES, 15, 8));
    }

    @Test
    void testHandlesItemsWithSameName() {
        Item[] items = items(
                item(ITEM_NAME, 3, 4),
                item(ITEM_NAME, 16, 7));
        assertContains(updateQuality(items),
                item(ITEM_NAME, 2, 3),
                item(ITEM_NAME, 15, 6));
    }

    @Test
    void testHandlesMultipleDays() {
        int sellIn = 4, quality = 5, days = 2;
        Item[] items = items(item(ITEM_NAME, sellIn, quality));
        assertContains(updateQualityXDays(items, days), item(ITEM_NAME, sellIn-days, quality-2));
    }

    Item[] updateQuality(Item[] items) {
        return updateQualityXDays(items, 1);
    }

    Item[] updateQualityXDays(Item[] items, int days) {
        GildedRose app = new GildedRose(items);
        for (int i = 0; i < days; i++) {
            app.updateQuality();
        }
        return app.items();
    }

    private static Item[] items(Item... items) {
        return items;
    }

    private static Item item(String name, int sellIn, int quality) {
        return new Item(name, sellIn, quality);
    }

    /**
     * The asserts here are workarounds due to the fact that the Item Class cannot be modified
     * Otherwise we could use assertThat of google.Truth on iterables by adding the equals method to the Item Class
     */
    private static void assertContains(Item[] actualItems, Item... expectedItems) {
        assertThat(actualItems.length).isEqualTo(expectedItems.length);
        for (int i = 0; i < actualItems.length; i++) {
            assertThat(actualItems[i].toString()).isEqualTo(expectedItems[i].toString());
        }
    }
}
