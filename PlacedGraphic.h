#pragma once
#include"Point.h"
#include "VectorGraphic.h"

namespace Framework {

	using namespace VG;
	
	class PlacedGraphic {
		
	public:
		PlacedGraphic();
		PlacedGraphic(const Point& placement, const HVectorGraphic& vg);
		PlacedGraphic(Point&& placement, const HVectorGraphic& vg);
		PlacedGraphic(const Point& placement, HVectorGraphic&& vg);
		PlacedGraphic(Point&& placement, HVectorGraphic&& vg);

		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) = default;

		PlacedGraphic& operator=(const PlacedGraphic&) = default;
		PlacedGraphic& operator=(PlacedGraphic&&) = default;

		
		void setPlacementPoint(const Point& placement);
		void setPlacementPoint(Point&& placement);
		const Point& getPlacementPoint() const;

		void setGraphic(const HVectorGraphic& graphic);
		void setGraphic(HVectorGraphic&& graphic);
		const VectorGraphic& getGraphic() const;

		bool operator==(const PlacedGraphic& rhs) const;
		bool operator!=(const PlacedGraphic& rhs) const;

	private:
		Point placementPoint;
		HVectorGraphic graphic;
	};	
}