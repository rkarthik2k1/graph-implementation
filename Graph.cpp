#include "Graph.h"
#include <iostream>

//GraphNode implementation
void GraphNode::AddEdge(const string& strEdge)
{
   if (!IsEdge(strEdge))
   {
      m_strEdges.push_back(strEdge);
   }
}

bool GraphNode::IsEdge(const string& strEdge)
{
   bool bRet = false;
   int len = m_strEdges.size();
   for (int i = 0; i < len; i++)
   {
      if (m_strEdges[i] == strEdge)
      {
         bRet = true;
         break;
      }
   }

   return bRet;
}

// Graph Implementation
bool Graph::IsPresent(const string& strName)
{
   bool bRet = false;
   int size = m_Graph.size();
   for (int i = 0; i < size; i++)
   {
      if (m_Graph[i].GetName() == strName)
      {
         bRet = true;
         break;
      }
   }
   return bRet;
}

void Graph::AddNode(const string& strName, const vector<string>& strEdges)
{
   GraphNode node(strName, strEdges);
   if (!IsPresent(strName))
   {
      m_Graph.push_back(node);
   }
}

bool Graph::IsEdge(const string& strStart, const string& strEnd)
{
   bool bRet = false;
   GraphNode node{};
   if (FindNode(strStart, node))
   {
      if (node.IsEdge(strEnd))
      {
         std::cout << strStart << " has an edge with " << strEnd << "\n";
      }
      else
      {
         std::cout << strStart << " does not have an edge with " << strEnd << "\n";
      }
   }
   return bRet;
}

bool Graph::FindNode(const string strName, GraphNode& node)
{
   bool bRet = false;
   int size = m_Graph.size();
   for (int i = 0; i < size; i++)
   {
      if (m_Graph[i].GetName() == strName)
      {
         node = m_Graph[i];
         bRet = true;
         break;
      }
   }
   return bRet;
}

bool Graph::IsRoute(const string strStart, const string strEnd)
{
   GraphNode nodeStart{};

   // Validate if strStart exists in the graph
   bool bRet = FindNode(strStart, nodeStart);

   // If strStart exists, make sure it is different than strEnd
   // else we can simply return true
   if (bRet && (strStart != strEnd))
   {
      // Validate if strEnd exists in the graph
      bRet = IsPresent(strEnd);
      if (bRet)
      {
         // Get edges of strStart and check if strEnd can be found
         // as one of its edges or edges of its edges, recursively
         vector <string> edges = nodeStart.GetEdges();
         for (int i = 0; i < edges.size(); i++)
         {
            // Is strEnd one of its edges
            if (strEnd == edges[i])
            {
               bRet = true;
               break;
            }
            else
            {
               // If not, check recursivley within its edges till
               bRet = IsRoute(edges[i], strEnd);
               if (bRet)
               {
                  break;
               }
            }
         }
      }
   }
   if (bRet)
   {
      std::cout << strStart << " has a route to " << strEnd << "\n";
   }
   else
   {
      std::cout << strStart << " does not have a route to " << strEnd << "\n";
   }
   return bRet;
}