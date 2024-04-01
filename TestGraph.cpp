#include "Graph.h"

void BuildGraph()
{
   Graph graph{};

   // Add f - a, b, c edges
   graph.AddNode("f", {"a", "b", "c"});

   // Add a - e edge
   graph.AddNode("a", {"e"});

   // Add b - a, h edges
   graph.AddNode("b", {"a", "h"});

   // Add c - a edge
   graph.AddNode("c", {"a"});

   // Add e - no edge
   graph.AddNode("e", {""});

   // Add h - no edge
   graph.AddNode("h", {""});

   // Add d - g edge
   graph.AddNode("d", {"g"});

   // Add g - no edge
   graph.AddNode("g", {""});

   graph.IsEdge("f", "c");

   graph.IsEdge("f", "h");

   graph.IsRoute("f", "e");
   graph.IsRoute("f", "h");
   graph.IsRoute("f", "g");
   graph.IsRoute("c", "e");
   graph.IsRoute("c", "b");
}

int main()
{
   BuildGraph();
}