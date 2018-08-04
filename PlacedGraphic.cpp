#include "PlacedGraphic.h"

namespace Framework {
	
	PlacedGraphic::PlacedGraphic()
		: placementPoint(Point(0,0)),
		graphic(new VG::VectorGraphic())
	{
	}

	PlacedGraphic::PlacedGraphic(const Point& placement, const HVectorGraphic& vg)	
		: placementPoint(placement),
		graphic(vg)
	{
	}

	PlacedGraphic::PlacedGraphic(Point&& placement, const HVectorGraphic& vg)
		: placementPoint(std::move(placement)),
		graphic(vg)
	{
	}

	PlacedGraphic::PlacedGraphic(const Point& placement, HVectorGraphic&& vg)
		: placementPoint(placement),
		graphic(std::move(vg))
	{
	}

	PlacedGraphic::PlacedGraphic(Point&& placement, HVectorGraphic&& vg)
		: placementPoint(std::move(placement)),
		graphic(std::move(vg))
	{
	}


	void PlacedGraphic::setPlacementPoint(const Point& placement) 
	{
		placementPoint = placement;
	}

	void PlacedGraphic::setPlacementPoint(Point&& placement)
	{
		placementPoint = { std::move(placement) };
	}

	Point const& PlacedGraphic::getPlacementPoint() const
	{
		return placementPoint; 
	};

	void PlacedGraphic::setGraphic(const HVectorGraphic& graphic) 
	{
		this->graphic = graphic;		
	}	
	
	void PlacedGraphic::setGraphic(HVectorGraphic&& graphic)
	{
		this->graphic = { std::move(graphic) };
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