template <typename LoaderStrategy>
void ResourceLoader::setLoaderStrategy(const LoaderStrategy& factory) {
	usedLoaderStrategy = factory;
}