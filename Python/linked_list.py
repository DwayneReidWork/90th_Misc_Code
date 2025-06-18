class Node:
    def __init__(self,value):
        self.value = value
        self.next = None
        
# node1 = Node(10)
# node2 = Node(20)
# node1.next = node2

# print(node1.value)
nodes = []
for i in range(10):
    nodes.append(Node(i*2))
    nodes[i-1].next = nodes[i]

for i in range(10):
    print("Node:",nodes[i])
    print("Node value:",nodes[i].value)
    print("Next node:",nodes[i].next)
    
print(nodes[1].next.value)