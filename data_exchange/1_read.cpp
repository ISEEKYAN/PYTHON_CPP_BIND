#include <chrono>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <vector>

using namespace std;
using namespace chrono;
// for convenience
using json = nlohmann::json;

void test_json() {
  ifstream fin("../test.json", ios::in);
  json j;
  fin >> j;
  vector<int> l = j["list"];
  cout << j["float_list"][1] << "\n";

  fin.seekg(ios::beg);
  stringstream ss;
  ss << fin.rdbuf();
  const string str = ss.str();
  auto start = system_clock::now();
  for (int i = 0; i < 10; ++i) {
    auto x = json::parse(str);
  }
  cout << "time in s: "
       << 0.000'001 *
              duration_cast<microseconds>(system_clock::now() - start).count();
  cout << "\n";
}

void test_bson() {
  ifstream fin("../test.bson", ios::in | ios::binary);
  // json j;
  // fin >> j;
  // vector<int> l = j["list"];
  // cout << j["float_list"][1] << "\n";

  fin.seekg(ios::beg);
  stringstream ss;
  ss << fin.rdbuf();
  string str = ss.str();
  auto start = system_clock::now();
  for (int i = 0; i < 10; ++i) {
    auto x = json::from_bson(str);
  }
  cout << "time in s: "
       << 0.000'001 *
              duration_cast<microseconds>(system_clock::now() - start).count();
  cout << "\n";
}

void test_msgpack() {
  ifstream fin("../test.msgpack", ios::in | ios::binary);
  // json j;
  // fin >> j;
  // vector<int> l = j["list"];
  // cout << j["float_list"][1] << "\n";

  fin.seekg(ios::beg);
  stringstream ss;
  ss << fin.rdbuf();
  string str = ss.str();
  auto start = system_clock::now();
  for (int i = 0; i < 10; ++i) {
    auto x = json::from_msgpack(str);
  }
  cout << "time in s: "
       << 0.000'001 *
              duration_cast<microseconds>(system_clock::now() - start).count();
  cout << "\n";
}

int main() {
  cout << "test json:\n";
  test_json();
  cout << "test bson:\n";
  test_bson();
  cout << "test msgpack:\n";
  test_msgpack();
}