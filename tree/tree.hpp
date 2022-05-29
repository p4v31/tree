#include <iostream>
#include <memory>

struct tree_node {
  int value;
  tree_node *up;
  std::unique_ptr<tree_node> left, right;

  friend auto operator<<(std::ostream &out, tree_node &node) -> std::ostream &;
};

struct tree {
  std::unique_ptr<tree_node> root;

  auto find(int val) -> tree_node *;
  auto find_successor(tree_node *node) -> tree_node *;
  auto insert(int val) -> tree_node *;
  auto remove(int val) -> bool;
  auto delete_node(std::unique_ptr<tree_node> node, int val) -> std::unique_ptr<tree_node>;
  friend auto operator<<(std::ostream &out, tree &tree) -> std::ostream &;
};
