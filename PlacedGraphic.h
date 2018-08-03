#pragma once
#include"Point.h"
#include "VectorGraphic.h"

namespace Framework {

	using namespace VG;
	
	class PlacedGraphic {
		
	public:
		PlacedGraphic();
		PlacedGraphic(const Point& placement, HVectorGraphic vg);

		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) = default;

		PlacedGraphic& operator=(const PlacedGraphic&) = default;
		PlacedGraphic& operator=(PlacedGraphic&&) = default;

		
		void setPlacementPoint(Point const& placement);
		Point const& getPlacementPoint() const;

		void setGraphic(HVectorGraphic const& graphic);
		VectorGraphic const& getGraphic() const;

		bool operator==(const PlacedGraphic& rhs) const;
		bool operator!=(const PlacedGraphic& rhs) const;

	private:
		Point placementPoint;
		HVectorGraphic graphic;
	};	
}