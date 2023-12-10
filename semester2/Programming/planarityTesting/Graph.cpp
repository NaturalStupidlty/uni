#include "Graph.h"
#include <algorithm>

Graph Graph::GetCycle()
{
    vector<Vertex> usedVertices;

    return FindCycle(usedVertices,Vertex{1},Vertex{-1});
}

Graph Graph::FindCycle(vector<Vertex> usedVertices, Vertex currVertex, Vertex parentVertex)
{
    usedVertices.push_back(currVertex);

    for(auto vertex: AdjList[currVertex])
    {
        if (find(usedVertices.begin(),usedVertices.end(),vertex)==usedVertices.end())
        {
            Graph result = FindCycle(usedVertices,vertex,currVertex);
            if (!result.AdjList.empty())
            {
                return result;
            }
        }
        else if (vertex != parentVertex)
        {
            vector<Vertex> cycleVector;
            cycleVector.insert(cycleVector.begin(), find(usedVertices.begin(), usedVertices.end(), vertex), usedVertices.end());
            // Додати внутрішню грань циклу
            planes.push_back(cycleVector);
            // Додати зовнішню грань циклу
            planes.push_back(cycleVector);
            map<Vertex, vector<Vertex>> result;
            result[cycleVector[0]] = {cycleVector[1],cycleVector[cycleVector.size()-1]};
            result[cycleVector[cycleVector.size()-1]] = {cycleVector[0],cycleVector[cycleVector.size()-2]};
            for (int i = 1; i < cycleVector.size()-1; i++)
            {
                result[cycleVector[i]] = {cycleVector[i-1],cycleVector[i+1]};
            }
            return result;
        }
    }
    return Graph();
}

Segment Graph::GetSegment(Graph cycle)
{
    using namespace std;

    for (auto const& pair:cycle.AdjList)
    {
        vector<Vertex>::iterator cycleVertexAdjBegin = cycle.AdjList[pair.first].begin();
        vector<Vertex>::iterator cycleVertexAdjEnd = cycle.AdjList[pair.first].end();
        for (auto graphVertex:AdjList[pair.first])
        {
            if (find(cycleVertexAdjBegin,cycleVertexAdjEnd,graphVertex)==cycleVertexAdjEnd)
            {
                vector<Vertex> usedVertices;
                usedVertices.push_back(pair.first);
                Segment segment = FindSegment(cycle,graphVertex,usedVertices);
                return segment;
                // Segment to graph algorithm
                /*int segmentSize = segment.SegmentVector.size();
                map<Vertex, vector<Vertex>> segmentMap;
                segmentMap[segment[0]] = {segment[1]};
                segmentMap[segment[segmentSize-1]] = {segment[segmentSize-2]};
                for(int i = 1;i<segmentSize-1;i++)
                {
                   segmentMap[segment[i]] = {segment[i-1],segment[i+1]};
                }*/
            }
        }
    }
    return Segment(vector<Vertex>{Vertex{-1}});
}

Segment Graph::FindSegment(const Graph &cycle, Vertex currVertex, vector<Vertex> usedVertices)
{
    usedVertices.push_back(currVertex);
    if(cycle.AdjList.count(currVertex) == 0)
    {
        for(auto vertex:AdjList[currVertex])
        {
            if(find(usedVertices.begin(),usedVertices.end(),vertex)==usedVertices.end())
            {
                Segment result = FindSegment(cycle,vertex,usedVertices);
                return result;
            }
        }
    }
    return Segment(usedVertices);
}

bool Graph::CheckPlanarity(Graph cycle)
{
    Segment currSegment = GetSegment(cycle);
    while (currSegment[0].number != -1)
    {
        bool isPlaceForSegmentFound = false;
        for(auto plane:planes)
        {
            bool isStartInPlane = false, isEndInPlane = false;
            for(auto vertex:plane)
            {
                if(vertex==currSegment[0])
                {
                    isStartInPlane = true;
                }
                else if(vertex == currSegment.SegmentVector.back())
                {
                    isEndInPlane = true;
                }
            }
            if(isStartInPlane&&isEndInPlane)
            {
                //Вставити сегмент в цикл
                int segmentSize = (int)currSegment.SegmentVector.size();
                cycle.AdjList[currSegment[0]].push_back(currSegment[1]);
                cycle.AdjList[currSegment[segmentSize-1]].push_back(currSegment[segmentSize-2]);
                for(int i = 1;i<segmentSize-1;i++)
                {
                    cycle.AdjList[currSegment[i]].push_back(currSegment[i-1]);
                    cycle.AdjList[currSegment[i]].push_back(currSegment[i+1]);
                }
                //Розділити відповідну грань на 2
                vector<Vertex> firstPlane;
                vector<Vertex> secondPlane;

                vector<Vertex>::iterator segmentStart = currSegment.SegmentVector.begin();
                vector<Vertex>::iterator segmentEnd = currSegment.SegmentVector.end()-1;

                vector<Vertex>::iterator segmentStartInPlane = find(plane.begin(),plane.end()
                        ,currSegment.SegmentVector.front());
                vector<Vertex>::iterator segmentEndInPlane = find(plane.begin(),plane.end()
                        ,currSegment.SegmentVector.back());

                if(segmentStartInPlane>segmentEndInPlane)
                {
                    reverse(segmentStart,segmentEnd+1);
                    vector<Vertex>::iterator temp = segmentStartInPlane;
                    segmentStartInPlane = segmentEndInPlane;
                    segmentEndInPlane = temp;
                }

                firstPlane.insert(firstPlane.begin(),segmentStartInPlane,segmentEndInPlane+1);
                reverse(segmentStart+1,segmentEnd);
                firstPlane.insert(firstPlane.end(),segmentStart+1, segmentEnd);
                reverse(segmentStart+1,segmentEnd);

                secondPlane.insert(secondPlane.begin(),segmentStart,segmentEnd+1);
                secondPlane.insert(secondPlane.begin(),plane.begin(),segmentStartInPlane);
                secondPlane.insert(secondPlane.end(),segmentEndInPlane+1,plane.end());

                planes.erase(find(planes.begin(),planes.end(),plane));
                planes.insert(planes.begin(),firstPlane);
                planes.insert(planes.begin(),secondPlane);
                isPlaceForSegmentFound = true;
                break;
            }
        }
        if(!isPlaceForSegmentFound)
        {
            return false;
        }
        currSegment = GetSegment(cycle);
    }
    return true;
}
