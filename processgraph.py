import csv
import pydot


graph = pydot.Dot(graph_type='graph')
with open("output.csv") as input_file:
    process_reader = list(csv.DictReader(input_file))
  
    root_level = 0
    root = process_reader[0]['ppid']
    root_node = pydot.Node(root, label = "PID: %s\nLevel: %s\n" %(root, root_level))
    graph.add_node(root_node)
    
    for i in process_reader:
        pid = i['pid']
        level = i['level']
        node = pydot.Node(pid, label = "PID: %s\nLevel: %s\n" %(pid, level))
        graph.add_node(node)
        edge = pydot.Edge(i['ppid'], i['pid'])
        graph.add_edge(edge)

graph.write_png('graph.png')
    
   



 
