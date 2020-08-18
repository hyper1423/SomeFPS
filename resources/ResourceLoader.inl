template <typename TypeFactory>
void ResourceLoader::registerFactory(const TypeFactory& factory) {
	usedFactory = factory;
}