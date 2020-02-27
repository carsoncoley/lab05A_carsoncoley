#include "tddFuncs.h"
#include "WordCount.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	WordCount test1;
	assertEquals(0, test1.getTotalWords(), "Empty WordCount", 9);
	test1.incrWordCount("49Hello-67");
	assertEquals(1, test1.getTotalWords(), "WordCount with 1 word", 11);
	test1.incrWordCount("78*$Hey579");
	test1.incrWordCount("%*h0i");
	assertEquals(3, test1.getTotalWords(), "WordCount with 3 words", 14);
	WordCount test2;
	test2.incrWordCount("49Hello-67");
	assertEquals(1, test2.getTotalWords(), "Test Increment on Empty WordCount", 17);
	test2.incrWordCount("%*h0i");
	assertEquals(2, test2.getTotalWords(), "Test Increment on WordCount with 1 Word", 19);
	test2.incrWordCount("yo4*%l8o-");
	test2.incrWordCount("$$su6p");
	assertEquals(4, test2.getTotalWords(), "Test Increment on WordCount with 3 Words", 22);
	WordCount test3;
	assertEquals("hello", test3.makeValidWord("*87565Hello84--"), "Test MakeValidWord #1", 24);
	assertEquals("hi", test3.makeValidWord("%*h90i5'4"), "Test MakeValidWord #2", 25);
	assertEquals("surfboard", test3.makeValidWord("s5@ur4fb9oa%rd-"), "Test MakeValidWord #3", 26);
	assertEquals("water", test3.makeValidWord("%WAt3er--"), "Test MakeValidWord #4", 27);
	
	assertEquals(0, test3.getTotalWords(), "Test GetTotalWords on empty WordCount", 29);
	assertEquals(4, test2.getTotalWords(), "Test GetTotalWords", 30);
	assertEquals(3, test1.getTotalWords(), "Test GetTotalWords", 31);
	assertEquals(true, test3.isWordChar('c'), "Test IsWordChar #1", 32);
	assertEquals(false, test3.isWordChar('%'), "Test IsWordChar #2", 33);
	assertEquals(false, test3.isWordChar('4'), "Test IsWordChar #3", 34);
	WordCount test4;
	test4.addAllWords("my favorite/nfood/t8745");
	assertEquals(3, test4.getTotalWords(),"Test AddAllWords #1", 36);
	WordCount test5;
	test5.incrWordCount("a");
	test5.incrWordCount("a");
	test5.incrWordCount("b");
	test5.incrWordCount("c");
	std::cout << "Expected result for DumpWordsSortedbyWord #1: " <<endl;
	std::cout << "c,1" << endl;
	std::cout << "b,1" << endl;
	std::cout << "a,2" << endl;
	std::cout << "Actual result for DumpWordsSortedbyWord #1: " <<endl;
	test5.dumpWordsSortedByWord(cout);
	test5.incrWordCount("d");
	test5.incrWordCount("dd");
	test5.incrWordCount("a");
	std::cout<< "Expected result for DumpWordsSortedbyWord #2: " << endl;
	std::cout << "dd,1" << endl;
	std::cout << "d,1" << endl;
	std::cout << "c,1" << endl;
	std::cout << "a,3" << endl;
	std::cout << "Actual result for DumpWordsSortedbyWord #2: " << endl;
	test5.dumpWordsSortedByWord(cout);

	std::cout<< "Expected result for DumpWordsSortedbyOccurence #1: " << endl;
	std::cout<<"b,1"<<endl;
	std::cout<<"c,1"<<endl;
	std::cout<<"d,1"<<endl;
	std::cout<<"dd,1"<<endl;
	std::cout<<"a,3"<<endl;
	std::cout<<"Actual result for DumpWordsSortedbyOccurence #1: "<<endl;
	test5.dumpWordsSortedByOccurence(cout);
	
	WordCount test6;
	test6.incrWordCount("apple");
	test6.incrWordCount("ant");
	test6.incrWordCount("apple");
	test6.incrWordCount("shoe");
	test6.incrWordCount("apple");
	test6.incrWordCount("ant");
	test6.incrWordCount("sock");

	std::cout<<"Expected result for DumpWordsSortedbyOccurence #2: "<<endl;
	std::cout<<"shoe,1"<<endl;
	std::cout<<"sock,1"<<endl;
	std::cout<<"ant,2"<<endl;
	std::cout<<"apple,3"<<endl;
	std::cout<<"Actual result for DumpWordsSortedbyOccurence #2: "<<endl;
	test6.dumpWordsSortedByOccurence(cout);
	return 0;
}
