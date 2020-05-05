package com.gildedrose.UpdateStrategy;

import com.gildedrose.ITEM_KEYWORDS;
import com.gildedrose.ITEM_NAMES;
import com.gildedrose.Item;

import java.util.Map;
import java.util.TreeMap;

public class UpdateStrategyFactory {
    private Map<String, UpdateStrategy> exactKeyUpdateStrategyMap = new TreeMap<>();
    private Map<String, UpdateStrategy> containsKeyUpdateStrategyMap = new TreeMap<>();
    private UpdateStrategy defaultUpdateStrategy = new DefaultUpdateStrategy();

    public UpdateStrategyFactory() {
        exactKeyUpdateStrategyMap.put(ITEM_NAMES.SULFURAS.name, new DoNothingUpdateStrategy());
        exactKeyUpdateStrategyMap.put(ITEM_NAMES.BACKSTAGE_PASSES.name, new TicketUpdateStrategy());
        exactKeyUpdateStrategyMap.put(ITEM_NAMES.BRIE.name, new GetBetterWithTimeUpdateStrategy());

        containsKeyUpdateStrategyMap.put(ITEM_KEYWORDS.CONJURED.name, new ConjuredUpdateStrategy());
    }

    public UpdateStrategy getStrategy(Item item) {
        if (exactKeyUpdateStrategyMap.containsKey(item.name)) {
            return exactKeyUpdateStrategyMap.get(item.name);
        }

        for (Map.Entry<String, UpdateStrategy> entry : containsKeyUpdateStrategyMap.entrySet()) {
            if (item.name.contains(entry.getKey())) {
                return entry.getValue();
            }
        }

        return defaultUpdateStrategy;
    }
}
