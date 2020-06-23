#pragma once
#include "pch.h"
#include "Binder.h"
#include <type_traits>
#include <memory>
#include <unordered_map>

class BinderManager
{
public:
	template<class T,typename...Params>
	static std::shared_ptr<T> AddBinder(Graphics& gfx, Params&&... p) noxnd
	{
		static_assert(std::is_base_of<Binder, T>::value, "Can only add classes derived from Binder");
		return Get().AddBinder_<T>(gfx, std::forward<Params>(p)...);
	}
private:
	template<class T,typename ... Params>
	std::shared_ptr<T> AddBinder_(Graphics& gfx, Params&& ...p) noxnd
	{
		const auto key = T::GenerateUID(std::forward<Params>(o)...);
		const auto i = binds.con.find(key);
		if (i == binds.end())
		{
			auto bind = std::make_shared<T>(gfx, std::forward<Params>(p)...);
			binds[key] = bind;
			return bind;
		}
		else
		{
			return std::static_pointer_cast<T>(i->second);
		}
	}
	static BinderManager& Get()
	{
		static BinderManager BinderMgr;
		return BinderMgr;
	}
private:
	std::unordered_map<std::string, std::shared_ptr<Binder>> binds;
};

