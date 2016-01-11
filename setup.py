from setuptools import setup

setup(
    name="mecacellgenerator",
    version="0.0.1",
    author="Jean Disset",
    author_email="j.disset@gmail.com",
    packages=['mecacellgenerator', 'mecacellgenerator.templates'],
    entry_points={
        'console_scripts': ['mecacellgen = mecacellgenerator:main', ],
    }
    include_package_data=True,
    package_data={'mecacellgenerator.templates': ['*']},
    description="Basic project scaffolding tool for the cell simulation library Mecacell",
    license="MIT",
)
