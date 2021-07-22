int main()
{
  // Simply using the Thomas Hobbes's Leviathan example from Wikipedia to do basic testing
	cout << base64encode("M") << endl; // TQ==
	cout << base64encode("Ma") << endl; // TWE=
	cout << base64encode("Man") << endl; // TWFu
	cout << base64encode("Man ") << endl; // TWFuIA==
	cout << base64encode("Man i") << endl; // TWFuIGk=
	cout << base64encode("Man is") << endl; // TWFuIGlz

	return 0;
}
