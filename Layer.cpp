#include "Layer.h"    


namespace Framework
{

	Layer::Layer()
		:alias("")
	{}

	Layer::Layer(const std::string& alias)
		:alias(alias)
	{}	

	Layer::Layer(std::string&& alias)
		: alias(std::move(alias))
	{}

	Layer::PlacedGraphicIterator Layer::begin()
	{
		return graphics.begin();
	};

	Layer::PlacedGraphicIterator Layer::end()
	{
		return graphics.end();
	};

	void Layer::insert(const PlacedGraphic& placedGraphic) 
	{ 
		graphics.push_back(placedGraphic); 
	};		

	void Layer::insert(PlacedGraphic&& placedGraphic)
	{		
		graphics.emplace_back(std::move(placedGraphic));
	};
	
	void Layer::remove(const PlacedGraphic& placedGraphic)
	{
		PlacedGraphicIterator it = graphics.begin();

		while (it != graphics.end())
		{
			if ((*it) == placedGraphic)
			{
				graphics.erase(it);
				return;
			}
			else
			{
				it++;
			}
		}		
			throw std::invalid_argument("the placed graphic to remove does not appear in the layer.");
	};

	const Layer::PlacedGraphicCollection& Layer::getPlacedGraphics() const
	{
		return graphics;
	}

	void Layer::setAlias(const std::string& alias)
	{
		this->alias = alias;
	}
	
	void Layer::setAlias(std::string&& alias)
	{
		this->alias = { std::move(alias) };
	}

	std::string const& Layer::getAlias() const 
	{
		return alias; 
	};	

	bool Layer::operator==(const Layer& rhs) const
	{
		return (getAlias() == rhs.getAlias());
	}

	bool Layer::operator!=(const Layer& rhs) const
	{
		return !(*this == rhs);
	}
}