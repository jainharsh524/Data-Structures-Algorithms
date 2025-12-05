#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode
{
    int val;
    struct treeNode *left;
    struct treeNode *right;
    int height;
};

struct Queue
{
    struct treeNode *n;
    int lvl;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

struct treeNode *createNode(int val)
{
    struct treeNode *curr = (struct treeNode *)malloc(sizeof(struct treeNode));
    curr->val = val;
    curr->right = NULL;
    curr->left = NULL;
    curr->height = 0;
    return curr;
}

int height(struct treeNode *n)
{
    if (n == NULL)
    {
        return -1;
    }
    return n->height;
}

struct treeNode *insertion(struct treeNode *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    if (root->val < val)
    {
        root->right = insertion(root->right, val);
    }
    else if (root->val > val)
    {
        root->left = insertion(root->left, val);
    }
    root->height = 1 + max(height(root->left), height(root->right));
    return root;
}

struct treeNode *pred(struct treeNode *root)
{
    struct treeNode *curr = root->left;
    while (curr != NULL && curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}

struct treeNode *deletion(struct treeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val < key)
    {
        root->right = deletion(root->right, key);
    }
    else if (root->val > key)
    {
        root->left = deletion(root->left, key);
    }
    else
    {
        if (root->right == NULL)
        {
            struct treeNode *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            struct treeNode *temp = root->right;
            free(root);
            return temp;
        }
        struct treeNode *pre = pred(root);
        root->val = pre->val;
        root->left = deletion(root->left, pre->val);
    }
    return root;
}

bool search(struct treeNode *root, int val)
{
    if (root == NULL)
        return false;
    if (root->val == val)
        return true;
    else if (root->val < val)
        return search(root->right, val);
    else
        return search(root->left, val);
}

void preOrder(struct treeNode *root, FILE *out)
{
    if (root == NULL)
        return;
    fprintf(out, "%d ", root->val);
    preOrder(root->left, out);
    preOrder(root->right, out);
}

void inOrder(struct treeNode *root, FILE *out)
{
    if (root == NULL)
        return;
    inOrder(root->left, out);
    fprintf(out, "%d ", root->val);
    inOrder(root->right, out);
}

void postOrder(struct treeNode *root, FILE *out)
{
    if (root == NULL)
        return;
    postOrder(root->left, out);
    postOrder(root->right, out);
    fprintf(out, "%d ", root->val);
}

void levelOrder(struct treeNode *root, FILE *out)
{
    struct treeNode *queue[1000];
    int rear = 0;
    int front = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct treeNode *temp = queue[front++];
        fprintf(out, "%d ", temp->val);
        if (temp->left)
        {
            queue[rear++] = temp->left;
        }
        if (temp->right)
        {
            queue[rear++] = temp->right;
        }
    }
}

void topView(struct treeNode *root, FILE *out)
{
    if (root == NULL)
        return;
    struct Queue q[1000];
    int rear = 0;
    int front = 0;
    int map[1001];
    int offset = 500;
    int minHD = 300;
    int maxHD = -400;
    int filled[1001] = {0};
    // Queue temp;
    // temp.n = root;
    // temp.lvl = 0;
    q[rear++] = (struct Queue){root, 0};
    while (front < rear)
    {
        struct Queue temp = q[front++];
        int val = temp.n->val;
        int lvl = temp.lvl;
        if (!filled[lvl + offset])
        {
            filled[lvl + offset] = 1;
            map[lvl + offset] = val;
            if (lvl < minHD)
                minHD = lvl;
            if (lvl > maxHD)
                maxHD = lvl;
        }
        if (temp.n->left)
        {
            q[rear++] = (struct Queue){temp.n->left, lvl - 1};
        }
        if (temp.n->right)
        {
            q[rear++] = (struct Queue){temp.n->right, lvl + 1};
        }
    }
    for (int i = minHD; i < maxHD + 1; i++)
    {
        fprintf(out, "%d ", map[i + offset]);
    }
}

void bottomView(struct treeNode *root, FILE *out)
{
    if (root == NULL)
        return;
    struct Queue q[1000];
    int rear = 0;
    int front = 0;
    int map[1001];
    int offset = 500;
    int minHD = 300;
    int maxHD = -400;
    q[rear++] = (struct Queue){root, 0};
    while (front < rear)
    {
        struct Queue temp = q[front++];
        int val = temp.n->val;
        int lvl = temp.lvl;
        map[lvl + offset] = val;
        if (lvl < minHD)
            minHD = lvl;
        if (lvl > maxHD)
            maxHD = lvl;
        if (temp.n->left)
        {
            q[rear++] = (struct Queue){temp.n->left, lvl - 1};
        }
        if (temp.n->right)
        {
            q[rear++] = (struct Queue){temp.n->right, lvl + 1};
        }
    }
    for (int i = minHD; i < maxHD + 1; i++)
    {
        fprintf(out, "%d ", map[i + offset]);
    }
}

void rightView(struct treeNode *root, FILE *out)
{
    struct Queue q[1000];
    int front = 0;
    int rear = 0;
    int map[1000];
    int filled[1000] = {0};
    q[rear++] = (struct Queue){root, 0};
    int size = 0;
    while (front < rear)
    {
        struct Queue temp = q[front++];
        int val = temp.n->val;
        int lvl = temp.lvl;
        if (!filled[lvl])
        {
            filled[lvl] = 1;
            map[lvl] = val;
            size++;
        }
        if (temp.n->right)
        {
            q[rear++] = (struct Queue){temp.n->right, lvl + 1};
        }
        if (temp.n->left)
        {
            q[rear++] = (struct Queue){temp.n->left, lvl + 1};
        }
    }
    for (int i = 0; i < size; i++)
    {
        fprintf(out, "%d ", map[i]);
    }
}

void leftView(struct treeNode *root, FILE *out)
{
    struct Queue q[1000];
    int front = 0;
    int rear = 0;
    int map[1000];
    int filled[1000] = {0};
    q[rear++] = (struct Queue){root, 0};
    int size = 0;
    while (front < rear)
    {
        struct Queue temp = q[front++];
        int val = temp.n->val;
        int lvl = temp.lvl;
        if (!filled[lvl])
        {
            filled[lvl] = 1;
            map[lvl] = val;
            size++;
        }
        if (temp.n->left)
        {
            q[rear++] = (struct Queue){temp.n->left, lvl + 1};
        }
        if (temp.n->right)
        {
            q[rear++] = (struct Queue){temp.n->right, lvl + 1};
        }
    }
    for (int i = 0; i < size; i++)
    {
        fprintf(out, "%d ", map[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    struct treeNode *root = NULL;
    int choice, value;

    while (fscanf(input, "%d", &choice) == 1)
    {
        switch (choice)
        {
        case 1:
            fscanf(input, "%d", &value);
            root = insertion(root, value);
            fprintf(output, "Inserted %d\n", value);
            break;
        case 2:
            fscanf(input, "%d", &value);
            bool found = search(root, value);
            if (found)
            {
                fprintf(output, "Found %d\n", value);
            }
            else
            {
                fprintf(output, "Not Found %d\n", value);
            }
            break;
        case 3:
            fscanf(input, "%d", &value);
            root = deletion(root, value);
            fprintf(output, "Deleted %d\n", value);
            break;
        case 4:
            fprintf(output, "Preorder: ");
            preOrder(root, output);
            fprintf(output, "\n");
            break;
        case 5:
            fprintf(output, "Inorder: ");
            inOrder(root, output);
            fprintf(output, "\n");
            break;
        case 6:
            fprintf(output, "Postorder: ");
            postOrder(root, output);
            fprintf(output, "\n");
            break;
        case 7:
            fprintf(output, "Levelorder: ");
            levelOrder(root, output);
            fprintf(output, "\n");
            break;
        case 8:
            fprintf(output, "Height: %d\n", height(root));
            break;
        case 9:
            fprintf(output, "Top View: ");
            topView(root, output);
            fprintf(output, "\n");
            break;
        case 10:
            fprintf(output, "Bottom View: ");
            bottomView(root, output);
            fprintf(output, "\n");
            break;
        case 11:
            fprintf(output, "Right View: ");
            rightView(root, output);
            fprintf(output, "\n");
            break;
        case 12:
            fprintf(output, "Left View: ");
            leftView(root, output);
            fprintf(output, "\n");
            break;
        case 13:
            fclose(input);
            fclose(output);
            return 0;
        }
    }
}