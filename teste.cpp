#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.hpp"
#include "book.h"
#include "tree.h"


TEST_CASE("Testar tranformacao da palavra")
{
    string word = "bAn,ana";
    Book a;
    a.transformWord(word);
    CHECK(word == "banana");
}

TEST_CASE("Testar tranformacao da palavra")
{
    string word = "buA3n,3ana";
    Book a;
    a.transformWord(word);
    CHECK(word == "bua3n3ana");
}

TEST_CASE("Testar adicionar palavra pelo book")
{
    string word = "palavra";
    Tree tree;
    Book book;
    book.addWord(word, tree, 0);
    Node *node = tree.getRoot();

    CHECK(tree.getValue(node) == word);
    CHECK(tree.getCount(node, 0) == 1);
}

TEST_CASE("Testar inserir na arvore")
{
    string word = "palavra";
    Tree tree;
    tree.insert(word, 0);
    Node *node = tree.getRoot();

    CHECK(tree.getValue(node) == word);
    CHECK(tree.getCount(node, 0) == 1);
}

TEST_CASE("Testar getValue")
{
    Tree tree;
    Node *node = new Node("palavra", 0);
    string word = "palavra";
    string word2 = tree.getValue(node);
    CHECK(word2 == word);
}

TEST_CASE("Testar getCount")
{
    Tree tree;
    Node *node = new Node("palavra", 0);
    CHECK(tree.getCount(node, 0) == 1);
}