#include "Type.hpp"
#include "Common.hpp"

namespace IL2CPP { struct Array; }

List<System::MethodInfo*> System::Type::GetMethods()
{
	using func_t = IL2CPP::Array* (*)(Type* _this);

	func_t func = ::GetMethod<func_t>(TYPE_GETMETHODS);

	List<System::MethodInfo*> _list(func(this));

	return _list;
}

System::Type* System::Type::GetType()
{
	using func_t = Type * (*)(void* _this);

	func_t func = ::GetMethod<func_t>(TYPE_GETTYPE);

	return func(this);
}

System::Type* System::Type::GetType(void* object)
{
	using func_t = Type* (*)(void* _this);

	func_t func = ::GetMethod<func_t>(OBJECT_GETTYPE);

	return func(object);
}

System::MethodInfo* System::Type::GetMethod(const std::string& name)
{
	using func_t = MethodInfo * (*)(Type* _this, IL2CPP::String* name);

	func_t func = ::GetMethod<func_t>(TYPE_GETMETHOD);

	return func(this, IL2CPP::StringNew(name));
}

std::string System::Type::ToString(void* object)
{
	if (object == nullptr)
		return "ey men what are u doin";

	using func_t = IL2CPP::String* (*)(void* object);

	func_t func = ::GetMethod<func_t>(OBJECT_TOSTRING);

	auto x = func(object);

	if (x == nullptr)
		return "ey wtf dud";

	return IL2CPP::StringChars(x);
}

void* System::Type::EmptyTypes()
{
	return IL2CPP::GetField(IL2CPP::NewObject("System.Type"), "EmptyTypes");
}

System::ConstructorInfo* System::Type::GetConstructor(void* types)
{
	using func_t = System::ConstructorInfo* (*)(Type* _this, void* types);

	func_t func = ::GetMethod<func_t>(GETCONSTRUCTORINFO);

	return func(this, types);
}

System::Type* System::Type::GetType(const std::string& typeName)
{
	using func_t = Type * (*)(IL2CPP::String* _this);

	func_t func = ::GetMethod<func_t>(TYPE_GETTYPE_WITHNAME);

	return func(IL2CPP::StringNew(typeName));
}

std::string System::ReflectionUtils::PropGetName(MethodInfo* methodInfo)
{
	auto methods = Type::GetType("System.Reflection.MemberInfo")->GetMethod("get_Name");

	return IL2CPP::StringChars((IL2CPP::String*)methods->Invoke(methodInfo, nullptr));
}

List<System::ParameterInfo*> System::MethodInfo::GetParams()
{
	auto arr = (IL2CPP::Array*)Type::GetType("System.Reflection.MethodBase")->GetMethod("GetParameters")->Invoke(this, nullptr);
	List<System::ParameterInfo*> params(arr);
	return params;
}

void* System::MethodInfo::Invoke(void* obj, void* parameters)
{
	using func_t = void * (*)(MethodInfo* _this, void* obj, void* parameters);

	func_t func = ::GetMethod<func_t>(METHODBASE_INVOKE);

	return func(this, obj, parameters);
}

std::string System::ParameterInfo::Name()
{
	using func_t = IL2CPP::String* (*)(ParameterInfo* _this);

	func_t func = ::GetMethod<func_t>(PARAMAETERINFO_GETNAME);

	return IL2CPP::StringChars(func(this));
}

void* System::ConstructorInfo::Invoke(void* objectArray)
{
	using func_t = void* (*)(ConstructorInfo* _this, void* objectArray);

	func_t func = ::GetMethod<func_t>(CONSTRUCTORINFO_INVOKE);

	return func(this, objectArray);
}
