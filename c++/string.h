namespace utilss
{
    class string
    {
        private:
            char* data;
            int size;
        public:
            string();
            string(const string str);
            string(const char* c);

            ~string();

            string& operator=(const string &str);
            string& operator=(const char *c);

            bool operator==(const string &str)const;
            bool operator==(const char *c)const;

            char& operator[](int index);

            int size()
            {
                return size;
            }
            char* c_str(){return data;}

    };
}