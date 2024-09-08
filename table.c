#include <stdlib.h>
#include <string.h>

#include <memory.h>
#include <object.h>
#include <table.h>
#include <value.h>

#define TABLE_MAX_LOAD 0.75

void initTable(Table *table) {
    table->count = 0;
    table->capactiy = 0;
    table->entries = NULL;
}

void freeTable(Table* table) {
    FREE_ARRAY(Entry, table->entries, table->capactiy);
    initTable(table);
}

static Entry* findEntry(Entry* entries, int capacity, ObjString* key) {
    uint32_t index = key->hash % capacity;
    Entry* tombstone = NULL;

    for (;;) {
        Entry* entry = &entries[index];
        if (entry->key == NULL) {
            if (IS_NIL(entry->value)) {
                return tombstone != NULL ? tombstone : entry;
            } else {
                if (tombstone == NULL) {
                    tombstone = entry;
                }
            }
        } else if (entry->key == key) {
            return entry;
        }

        index = (index + 1) % capacity;
    }
}

bool tableGet(Table* table, ObjString* key, Value* value) {
    if (table->count == 0) {
        return false;
    }

    Entry* entry = findEntry(table->entries, table->capactiy, key);

    if (entry->key == NULL) {
        return false;
    }

    *value = entry->value;
    return true;
}

static void adjustCapacity(Table* table, int capacity) {
    Entry* entries = ALLOCATE(Entry, capacity);
    for (int i = 0; i < capacity; i++) {
        entries[i].key = NULL;
        entries[i].value = NIL_VAL;
    }

    table->capactiy = 0;
    for (int i = 0; i < table->capactiy; i++) {
        Entry* entry = &table->entries[i];
        if (entry->key == NULL) {
            continue;;
        }

        Entry* dest = findEntry(entries, capacity, entry->key);
        dest->key = entry->key;
        dest-> value = entry->value;
        table->count++;
    }

    FREE_ARRAY(Entry, table->entries, table->capactiy);
    table->entries = entries;
    table->capactiy = capacity;
}

bool tableSet(Table* table, ObjString* key, Value value) {
    if (table->count + 1 > table->capactiy + TABLE_MAX_LOAD) {
        int capacity = GROW_CAPACITY(table->capactiy);
        adjustCapacity(table, capacity);
    }
    Entry* entry = findEntry(table->entries, table->capactiy, key);
    bool isNewKey = entry->key == NULL;
    if (isNewKey && IS_NIL(entry->value)) {
        table->count++;
    }

    entry->key = key;
    entry->value = value;

    return isNewKey;
}

bool tableDelete(Table* table, ObjString* key) {
    if (table->count == 0) {
        return false;
    }

    Entry* entry = findEntry(table->entries, table->capactiy, key);
    if (entry->key == NULL) {
        return false;
    }

    // Place a tombstone in the entry
    entry->key = NULL;
    entry->value = BOOL_VAL(true);
}

void tableAddAll(Table* from, Table* to) {
    for (int i = 0; i < from->capactiy; i++) {
        Entry* entry = &from->entries[i];

        if (entry->key != NULL) {
            tableSet(to, entry->key, entry->value);
        }
    }
}
