#include "hashmap.h"

hashmap* map_construct(int size){
    hashmap* new_map = (hashmap*) malloc (sizeof(hashmap));
    new_map->container = (int64_t*) malloc (size * sizeof(int64_t));
    new_map->size = size;
    return new_map;
}

int hash(char* string){
    int hash_value = 0;
    for(int i = 0; i < (int)strlen(string); i++){
        hash_value *= P;
        hash_value += string[i] - 'A';
        hash_value %= N;
    }
    return hash_value;
}

void map_assign(hashmap* map, char* variable, int64_t value){
    int index = hash(variable);
    map->container[index] = value;
}

int64_t map_get(hashmap* map, char* variable){
    int index = hash(variable);
    return map->container[index];
}
