#pragma once

#include "Point.h"
#include <vector>
#include <memory>

namespace VG
{
    using Points = std::vector<Point>;		
	
    class VectorGraphic
    {
    public:
        VectorGraphic();
		        
		VectorGraphic(const VectorGraphic& other) = default;
		VectorGraphic(VectorGraphic&& other) = default;

		VectorGraphic& operator=(const VectorGraphic&) = default;
		VectorGraphic& operator=(VectorGraphic&&) = default;

        void addPoint(const Point& p);
		void addPoint(Point&& p);
        void removePoint(const Point& p);
        void erasePoint(int index);
        
        void openShape();
        void closeShape();
        
        bool isOpen() const;
        bool isClosed() const;
        
        int getWidth() const;
        int getHeight() const;
        
        std::size_t getPointCount() const;
        const Point& getPoint(int index) const;

		const Points& getPoints() const;
        
        bool operator==(const VectorGraphic& rhs) const;
        bool operator!=(const VectorGraphic& rhs) const;
        
    private:
        Points myPath;
        
        enum class ShapeStyle { Open, Closed } myShapeStyle;
    };

	//I'm not sure where this needs to go honestly. Seems like it should belong in the PlacedGraphic header, but it has to go inside the VG namespace somewhere. 
	using HVectorGraphic = std::shared_ptr<VectorGraphic>;

}
