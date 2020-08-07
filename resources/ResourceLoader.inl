template <typename TypeFactory>
void ResourceLoader::registerFactory(TypeFactory factory) {
	usedFactory = factory;
}