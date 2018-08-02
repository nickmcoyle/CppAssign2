#include "PlacedGraphic.h"

namespace Framework {
	
	PlacedGraphic::PlacedGraphic()
		: placementPoint(Point(0,0)),
		graphic(new VG::VectorGraphic())
	{
	}

	PlacedGraphic::PlacedGraphic(Point const& placement, HVectorGraphic vg)	
		: placementPoint(placement),
		graphic(vg)
	{
	}

	void PlacedGraphic::setPlacementPoint(Point const& placement) 
	{
		placementPoint = placement;
	}

	Point const& PlacedGraphic::getPlacementPoint() const
	{
		return placementPoint; 
	};

	void PlacedGraphic::setGraphic(HVectorGraphic const& graphic) 
	{
		this->graphic = graphic;		
	}	
	
	VectorGraphic const& PlacedGraphic::getGraphic() const
	{
		return (*graphic); 
	};

	bool PlacedGraphic::operator==(const PlacedGraphic& rhs) const
	{
		return (placementPoint == rhs.getPlacementPoint() && (*graphic) == rhs.getGraphic());
	}

	bool PlacedGraphic::operator!=(const PlacedGraphic& rhs) const
	{
		return !(*this == rhs);
	}

};