#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;
struct Point
{
    int x, y;
};
//distance betweent two points
double distance(Point p1, Point p2)
{  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); }
//compare wrt y-cooordinate
bool compareY(Point p1, Point p2)
{ return p1.y < p2.y;}
//  find closest pair of points in the strip of given size
double stripClosest(vector<Point> &strip, double d)
{
    double minDist = d;
    // Sort points by y-coordinate
    sort(strip.begin(), strip.end(), compareY);
    // Compare each point with its neighbors
    for (int i = 0; i < strip.size(); ++i)
    {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j)
        {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;}
//  find  closest pair of points (divide and conquer)
double closestPairUtil(vector<Point> &points, int left, int right)
{
    if (right - left <= 3)
    {
        // Base case: if there are 3 or fewer points, using brute force
        double minDist = numeric_limits<double>::max();
        for (int i = left; i <= right; ++i)
        {
            for (int j = i + 1; j <= right; ++j)
            {
                minDist = min(minDist, distance(points[i], points[j]));
            }
        }
        return minDist;}
    int mid = (left + right) / 2;
    Point midPoint = points[mid];
    // Recursively find the closest pair of points in left and right halves
    double leftDist = closestPairUtil(points, left, mid);
    double rightDist = closestPairUtil(points, mid + 1, right);
    double minDist = min(leftDist, rightDist);
    // Build a strip containing points close to the vertical line passing through the midpoint
    vector<Point> strip;
    for (int i = left; i <= right; ++i)
    {
        if (abs(points[i].x - midPoint.x) < minDist)
        {
            strip.push_back(points[i]);
        }
    }
    // Finding the closest pair of points in the strip
    double stripDist = stripClosest(strip, minDist);
    // Return the minimum of the distances
    return min(minDist, stripDist);
}
// Function to find the closest pair of points in the array
double closestPair(vector<Point> &points)
{
    // Sort points by x-coordinate
    sort(points.begin(), points.end(), [](Point p1, Point p2)
         { return p1.x < p2.x; });

    // Call utility function to find the closest pair of points
    return closestPairUtil(points, 0, points.size() - 1);
}
int main()
{   vector<Point> points = {{1, 2}, {5, 7}, {9, 10}, {3, 4}, {12, 15}, {8, 6}, {11, 14}, {2, 3}, {6, 9}, {13, 16}, {7, 8}, {4, 5}};
    double minDist = closestPair(points);
    cout << "The closest pair of points distance: " << minDist << endl;
    return 0;}
