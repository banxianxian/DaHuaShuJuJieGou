#include <iostream>
#include <queue>
using namespace std;
struct MinHeapNode{
	char d;
	unsigned frequency;
	MinHeapNode* lChild, * rChild;
	MinHeapNode(char d, unsigned frequency):d(d),frequency(frequency) {
		lChild = nullptr;
		rChild = nullptr;
	}
} ;
struct compare {
	bool operator() (MinHeapNode* first, MinHeapNode* second) {
		return first->frequency > second->frequency;
	}
 };

MinHeapNode* HuffmanCodes(char arr[], int frequency[], int size) {
	MinHeapNode* temp_lChild, * temp_rChild, * top;
	//��Ҷ�ڵ㰴��Ȩ�ؽ������򣬴�С���󣬷���һ�����ȶ�����
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> deQueue;
	//��Ҷ�ڵ����deQueue��
	for (int i = 0; i < size; i++) {
		deQueue.push(new MinHeapNode( arr[i],frequency[i] ));
	}
	// ����huffman tree
	//deQueue ��������κϲ������ֻ��һ��
	while (deQueue.size() != 1) {
		temp_lChild = deQueue.top();
		deQueue.pop();
		temp_rChild = deQueue.top();
		deQueue.pop();
		//$ �����Ҷ�ڵ�
		top = new MinHeapNode('$', temp_rChild->frequency + temp_lChild->frequency);
		top->lChild = temp_lChild;
		top->rChild = temp_rChild;
		deQueue.push(top);
	}
	return deQueue.top();


}

void printCodes(struct MinHeapNode* root, string str) {
	if (root == nullptr) {
		return;
	}
	if (root->d != '$') {
		cout << root->d << ": " << str << endl;
	}

	printCodes(root->lChild, str + '0');
	printCodes(root->rChild, str + '1');
}

int main() {

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int frequency[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	MinHeapNode* root = nullptr;
	root = HuffmanCodes(arr, frequency, size);
	printCodes(root, "");
	return 0;
}