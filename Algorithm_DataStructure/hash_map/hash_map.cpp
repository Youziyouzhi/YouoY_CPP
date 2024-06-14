#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Pair {
  int key;
  std::string val;
  Pair(int num, std::string s):key(num), val(s) {}
};

class ArrayHashMap{
private:
  std::vector<Pair *> buckets;
public:
  ArrayHashMap() {
    buckets = std::vector<Pair *>(100);
  }
  ~ArrayHashMap() {
    for (auto bucket : buckets) {
      delete bucket;
    }
    buckets.clear();
  }
  int hashFunc(int key) {
    int index = key % 100;
    return index;
  }
  std::string get(int key) {
    int index = hashFunc(key);
    Pair *p = buckets[index];
    if (p == nullptr) {
      return "";
    }
    return p->val;
  }
  void put(int key, std::string val) {
    Pair *p = new Pair(key, val);
    int index = hashFunc(key);
    buckets[index] = p;
  }
  void remove(int key) {
    int index = hashFunc(key);
    delete buckets[index];
    buckets[index] = nullptr;
  }
  std::vector<Pair *> pairSet() {
    std::vector<Pair *> pairset;
    for (Pair *pair : buckets) {
      if (pair != nullptr) {
        pairset.push_back(pair);
      }
    }
    return pairset;
  }
  std::vector<int> keySet() {
    std::vector<int> keyset;
    for(Pair *pair : buckets) {
      if (pair != nullptr) {
        keyset.push_back(pair->key);
      }
    }
    return keyset;
  }
  std::vector<std::string> valueSet() {
    std::vector<std::string> stringset;
    for (Pair *pair : buckets) {
      if (pair != nullptr) {
        stringset.push_back(pair->val);
      }
    }
    return stringset;
  }
  void print() {
    for (Pair *kv : buckets) {
      if(kv != nullptr) {
        std::cout<< kv->key << " -> " << kv->val << std::endl;
      }
    }
  }
};


void test1();
void test2();

int main() {
  // test1();
  test2();
  return 0;
}

void test1() {
  std::unordered_map<int, std::string> map;
  map[0] = "a";
  map[1] = "b";
  map[2] = "c";
  map[3] = "d";
  map[4] = "e";

  std::string name  = map[4];
  map.erase(4);

  for (auto k : map) {
    std::cout << k.first << " " << k.second << std::endl;
  }
  for (auto iter = map.begin(); iter != map.end(); iter++) {
    std::cout << iter->first << " -> " << iter->second << std::endl;
  }
}

void test2() {
  ArrayHashMap map = ArrayHashMap();

    /* 添加操作 */
    // 在哈希表中添加键值对 (key, value)
    map.put(12836, "小哈");
    map.put(15937, "小啰");
    map.put(16750, "小算");
    map.put(13276, "小法");
    map.put(10583, "小鸭");
    std::cout << "\n添加完成后，哈希表为\nKey -> Value" << std::endl;
    map.print();

    /* 查询操作 */
    // 向哈希表中输入键 key ，得到值 value
    std::string name = map.get(15937);
    std::cout << "\n输入学号 15937 ，查询到姓名 " << name << std::endl;

    /* 删除操作 */
    // 在哈希表中删除键值对 (key, value)
    map.remove(10583);
    std::cout << "\n删除 10583 后，哈希表为\nKey -> Value" << std::endl;
    map.print();

    /* 遍历哈希表 */
    std::cout << "\n遍历键值对 Key->Value" << std::endl;
    for (auto kv : map.pairSet()) {
        std::cout << kv->key << " -> " << kv->val << std::endl;
    }

    std::cout << "\n单独遍历键 Key" << std::endl;
    for (auto key : map.keySet()) {
        std::cout << key << std::endl;
    }

    std::cout << "\n单独遍历值 Value" << std::endl;
    for (auto val : map.valueSet()) {
        std::cout << val << std::endl;
    }

}