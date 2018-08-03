#include "Layer.h"    


namespace Framework
{
	Layer::PlacedGraphicIterator Layer::begin()
	{
		return graphics.begin();
	};

	Layer::PlacedGraphicIterator Layer::end()
	{
		return graphics.end();
	};

	Layer::Layer()
		:alias("")
	{}

	Layer::Layer(std::string const& alias)
		:alias(alias)
	{}	

	void Layer::insert(PlacedGraphic const& placedGraphic) 
	{ 
		graphics.push_back(placedGraphic); 
	};		

	void Layer::insert(PlacedGraphic&& placedGraphic)
	{		
		graphics.emplace_back(std::forward<PlacedGraphic>(placedGraphic));
	};
	
	void Layer::remove(PlacedGraphic const& placedGraphic)
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

	void Layer::setAlias(std::string const& alias)
	{
		this->alias = alias;
	}
	
	void Layer::setAlias(std::string&& alias)
	{
		this->alias = alias;
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