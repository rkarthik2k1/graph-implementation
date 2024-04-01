#pragma once
#include <vector>
#include <string>

using namespace std;

// Node in a graph
class GraphNode
{
   string m_strNodeName{};
   vector<string> m_strEdges{};

public:
   // default
   GraphNode()
   {
   }

   // Ctor with node name and a list of its edges
   GraphNode(const string& strName, const vector<string>& strEdges) :
      m_strNodeName(strName),
      m_strEdges(strEdges)
   {

   }
   string& GetName()
   {
      return m_strNodeName;
   }

   vector<string>& GetEdges()
   {
      return m_strEdges;
   }

   // Add an edge to this node
   void AddEdge(const string& strEdge);

   // Is the given string an edge to this node?
   bool IsEdge(const string& strEdge);
};

// Graph as a list of GraphNode objects
class Graph
{
   vector<GraphNode> m_Graph{};

   // Is node strName present in the graph
   bool IsPresent(const string& strName);
public:

   // Add a node to the graph
   void AddNode(const string& strName, const vector<string>& strEdges);

   // Is there an edge between strStart and strEnd?
   bool IsEdge(const string& strStart, const string& strEnd);

   // Find node with name strName
   bool FindNode(const string strName, GraphNode& node);

   // Is there a route between strStart and strEnd?
   bool IsRoute(const string strStart, const string strEnd);
};