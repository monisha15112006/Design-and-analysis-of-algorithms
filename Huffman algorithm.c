#include<stdio.h>
#include<stdlib.h>

struct Node {
   char data;
   float freq;
   struct Node *left, *right;
};

// Global variables for formula
float totalWeightedPathLength = 0;
float sumOfFrequencies = 0;
int maxBitSize = 0;

struct Node *createNode(char data, float freq) {
   struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->freq = freq;
   newNode->left = newNode->right = NULL;
   return newNode;
}

void swap(struct Node **a, struct Node **b) {
   struct Node *temp = *a;
   *a = *b;
   *b = temp;
}

void sort(struct Node* arr[], int n) {
   for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n - i - 1; j++) {
         if (arr[j]->freq > arr[j + 1]->freq) {
            swap(&arr[j], &arr[j + 1]);
         }
      }
   }
}

void printNodes(struct Node* nodes[], int size) {
   printf("\n NODES: \n");
   for (int i = 0; i < size; i++) {
      if(nodes[i]->data == '$')
         printf("(%.2f)", nodes[i]->freq);
      else
         printf("%c(%.2f)", nodes[i]->data, nodes[i]->freq);
   }
   printf("\n");
}

void printCodes(struct Node *root, int code[], int top) {
   if(root->left) {
      code[top] = 0;
      printCodes(root->left, code, top + 1);
   }
   if(root->right) {
      code[top] = 1;
      printCodes(root->right, code, top + 1);
   }
   if(!root->left && !root->right) {
      printf("%c: ", root->data);
      for(int i = 0; i < top; i++) {
         printf("%d", code[i]);
      }
      printf("\n");

      // Calculation tracking
      totalWeightedPathLength += (top * root->freq);
      sumOfFrequencies += root->freq;
      if (top > maxBitSize) maxBitSize = top; // Track maximum bit length
   }
}

void huffman(char data[], float freq[], int n) {
   struct Node* nodes[100];
   for(int i = 0; i < n; i++) {
      nodes[i] = createNode(data[i], freq[i]);
   }
   int size = n;
   while(size > 1) {
      sort(nodes, size);
      printNodes(nodes, size);
      struct Node* left = nodes[0];
      struct Node* right = nodes[1];
      printf("Combine:%.2f+%.2f=%.2f\n", left->freq, right->freq, left->freq + right->freq);
      struct Node* newNode = createNode('$', left->freq + right->freq);
      newNode->left = left;
      newNode->right = right;
      nodes[0] = newNode;
      for(int i = 1; i < size - 1; i++) {
         nodes[i] = nodes[i + 1];
      }
      size--;
   }
   printf("\nHUFFMAN CODES:\n");
   int code[100];
   printCodes(nodes[0], code, 0);

   // --- Compression Ratio Logic ---
   if (sumOfFrequencies > 0 && maxBitSize > 0) {
      float avgBitsPerChar = totalWeightedPathLength / sumOfFrequencies;
      float compressionRatio = ((maxBitSize - avgBitsPerChar) / maxBitSize) * 100;
      printf("Max Bit Size (L): %d\n", maxBitSize);
      printf("Average Bits per Character: %.2f\n", avgBitsPerChar);
      printf("Compression Ratio: %.2f%%\n", compressionRatio);
   }
}

int main() {
   int n;
   printf("Enter number of characters:");
   scanf("%d", &n);
   char data[n];
   float freq[n];
   for(int i = 0; i < n; i++) {
      printf("Enter the character %d:", i + 1);
      scanf(" %c", &data[i]);
      printf("Enter Frequency of %c :", data[i]);
      scanf("%f", &freq[i]);
   }
   huffman(data, freq, n);
   return 0;
}
