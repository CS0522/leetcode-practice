/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 * 解决思路: 双向链表 + 哈希表
 */

// @lc code=start
struct DNode
{
    int key, value;
    DNode* prev;
    DNode* next;
    DNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DNode(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    DNode(int k, int v, DNode* p, DNode* n): key(k), value(v), prev(p), next(n) {}
};

class LRUCache {
private:
    // 同一个链表的两个指针
    DNode* head = nullptr;
    DNode* tail = nullptr;
    int capacity;
    unordered_map<int, DNode*> key_dnode_mp;

    void _move_to_head(DNode* target_node)
    {
        // 如果本身就是头部，则无需操作
        if (target_node == head)
            return;
        // 如果是尾部，此时前面必有至少1个元素，先移动 tail 指针
        if (target_node == tail)
            tail = target_node->prev;
        // 如果是中间节点或尾部
        if (target_node->prev)
            target_node->prev->next = target_node->next;
        if (target_node->next)
            target_node->next->prev = target_node->prev;
        // 连接到头部
        target_node->prev = nullptr;
        target_node->next = head;
        head->prev = target_node;
        head = target_node;
    }

    void _add_to_head(int key, int value)
    {
        // 如果存在，则直接移到头部
        if (key_dnode_mp.count(key))
        {
            DNode* target_node = key_dnode_mp[key];
            target_node->value = value;
            return _move_to_head(target_node);
        }
        // 如果缓存满，则删除LRU末尾
        if (key_dnode_mp.size() >= capacity)
            _remove_from_tail();
        
        DNode *new_node = new DNode(key, value);
        // 最开始 head、tail 为空
        if (key_dnode_mp.size() == 0)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            // 连接头部
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        // 加入哈希表
        key_dnode_mp[key] = new_node;
    }

    void _remove_from_tail()
    {
        if (!tail)
            return;

        key_dnode_mp.erase(tail->key);
        if (key_dnode_mp.size() == 0)
        {
            head = nullptr;
            tail = nullptr;
            return;
        }
        // 此时队列有至少 2 个元素
        tail->prev->next = nullptr;
        DNode* tmp = tail;
        tail = tail->prev;
        delete tmp;
    }

    void print_lru(bool is_get, int key)
    {
        cout << (is_get ? "get: " : "put: ") << key << endl;
        cout << "lru_size: " << key_dnode_mp.size() << endl;
        DNode* p = head;
        while (p)
        {
            cout << "(" << p->key << ", " << p->value << ")" << endl;
            p = p->next;
        }
    }

public:
    LRUCache(int c) {
        capacity = c;
    }
    
    int get(int key) {
        if (!key_dnode_mp.count(key))
            return -1;
        DNode *target = key_dnode_mp[key];
        _move_to_head(target);
        // print_lru(1, key);
        return target->value;
    }
    
    void put(int key, int value) {
        _add_to_head(key, value);
        // print_lru(0, key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

