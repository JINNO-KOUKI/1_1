#pragma once

/// @brief ����̑o�������X�g�N���X
/// @tparam T �i�[����N���X
template <class T>
class MyList
{
	/// @brief ���X�g���̈�v�f��\���\����
	struct ElemData
	{
		/// @brief �i�[�v�f
		T _Elem;
		/// @brief ��O�̗v�f�ւ̃|�C���^
		ElemData* _Prev;
		/// @brief ���̗v�f�ւ̃|�C���^
		ElemData* _Next;

		/// @brief �f�t�H���g�R���X�g���N�^
		ElemData() : _Elem(T()), _Prev(nullptr), _Next(nullptr) {}

		/// @brief �����t���R���X�g���N�^(�O��v�f�ւ̃|�C���^��nullptr)
		/// @param inNewElem �i�[����v�f
		ElemData(T inNewElem) : _Elem(inNewElem), _Prev(nullptr), _Next(nullptr) {}

		/// @brief �����t���R���X�g���N�^
		/// @param inNewElem �i�[����v�f
		/// @param inPrev �O�̗v�f�ւ̃|�C���^
		/// @param inNext ��̗v�f�ւ̃|�C���^
		ElemData(T inNewElem, ElemData* inPrev, ElemData* inNext)
			: _Elem(inNewElem), _Prev(inPrev), _Next(inNext) {}
	};

public:
	/// @brief �f�t�H���g�R���X�g���N�^
	MyList() : _Front(nullptr), _Back(nullptr), _Size(0) {}
	/// @brief �f�t�H���g�f�X�g���N�^
	~MyList() { Clear(); }

	/// @brief �Ō���ɐV�K�v�f��ǉ�����
	/// @param inNewElem �ǉ��v�f
	inline void push_back(T inNewElem)
	{
		// �V�K�v�f�̍쐬
		ElemData* tElemData = new ElemData(inNewElem);

		if (!_Size)
		{	// ����v�f���i�[����Ă��Ȃ�

			// --�V�K�v�f��擪�v�f�E�Ō���v�f�ɓo�^
			_Front = tElemData;
			_Back = tElemData;
		}
		else
		{
			// �V�K�v�f�����݂̍Ō���v�f�̈��ɂ͈ʒu
			_Back->_Next = tElemData;
			// �V�K�v�f�̑O�Ɍ��݂̍Ō���v�f��o�^
			tElemData->_Prev = _Back;
			// �Ō���v�f��V�K�v�f�ɍX�V
			_Back = tElemData;
		}

		// �T�C�Y�̍X�V
		++_Size;
	}

	/// @brief �擪�ɐV�K�v�f��ǉ�����
	/// @param inNewElem �ǉ��v�f
	inline void push_front(T inNewElem)
	{
		// �V�K�v�f�̍쐬
		ElemData* tElemData = new ElemData(inNewElem);

		if (!_Size)
		{	// ����v�f���i�[����Ă��Ȃ�

			// -- �V�K�v�f��擪�v�f�E�Ō���v�f�ɓo�^
			_Front = tElemData;
			_Back = tElemData;
		}
		else
		{
			// �V�K�v�f�����݂̐擪�v�f�̈�O�ɔz�u
			_Front->_Prev = tElemData;
			// �V�K�v�f�̎��Ɍ��݂̐擪�v�f��o�^
			tElemData->_Next = _Front;
			// �擪�v�f��V�K�v�f�ɍX�V
			_Front = tElemData;
		}

		// �T�C�Y�̍X�V
		++_Size;
	}

	/// @brief �Ō���v�f�����X�g����폜����
	inline void pop_back()
	{
		// �v�f������Ȃ������珈�����Ȃ�
		if (!_Size) { return; }

		// ���݂̍Ō���v�f���擾
		ElemData* tElemData = _Back;

		// �Ō�̈��O�̗v�f���Ō���v�f�ɓo�^
		_Back = _Back->_Prev;
		// �V�K�Ō���v�f��Next��nullptr�ɍX�V
		_Back->_Next = nullptr;

		// ���̍Ō���v�f�����
		delete tElemData;

		// �T�C�Y�̍X�V
		--_Size;
	}

	/// @brief �擪�v�f�����X�g����폜����
	inline void pop_front()
	{
		// �v�f������Ȃ������珈�����Ȃ�
		if (!_Size) { return; }

		// ���݂̐擪�v�f���擾
		ElemData* tElemData = _Front;

		// �ŏ��̈��̗v�f��擪�v�f�ɓo�^
		_Front = _Front->_Next;
		// �V�K�擪�v�f��Prev��nullptr�ɍX�V
		_Front->_Prev = nullptr;

		// ���̐擪�v�f�����
		delete tElemData;

		// �T�C�Y�̍X�V
		--_Size;
	}

	/// @brief ���X�g���̂��ׂĂ̗v�f���폜����
	inline void Clear()
	{
		// �v�f��0��������I��
		if (!_Size) { return; }

		// �Ō���̗v�f���擾
		ElemData* tElemData = _Back;

		// -- �O�̗v�f��������Ȃ��Ȃ�܂ŌJ��Ԃ�
		while (tElemData = tElemData->_Prev)
		{
			// ���̗v�f���폜
			delete tElemData->_Next;
		}
		// �擪�v�f���폜
		delete _Front;

		// -- �����o�ϐ��̏�����
		_Front = nullptr;
		_Back = nullptr;
		_Size = 0;
	}

	/// @brief ���X�g�̐擪�v�f���擾����
	/// @return �擪�v�f
	inline T Front() const { return _Front->_Elem; }
	/// @brief ���X�g�̍Ō���v�f���擾����
	/// @return �Ō���v�f
	inline T Back() const { return _Back->_Elem; }
	/// @brief ���X�g�Ɋi�[����Ă���v�f�����擾����
	/// @return �v�f��
	inline constexpr unsigned int Size() const { return _Size; }

	/// @brief MyList�N���X�̃C�e���[�^
	class Iterator
	{
	public:
		/// @brief �f�t�H���g�R���X�g���N�^
		Iterator() : _Elem(nullptr) {}
		/// @brief �����t���R���X�g���N�^
		/// @param inElem �N�_�ƂȂ郊�X�g�v�f
		Iterator(ElemData* inElem) : _Elem(inElem) {}

	public:	// ���Z�q�I�[�o�[���[�h�Q
		T& operator*() const noexcept
		{
			return _Elem->_Elem;
		}
		T* operator->()
		{
			return &(_Elem->_Elem);
		}
		Iterator operator++(int)
		{
			_Elem = _Elem->_Next;
			return this;
		}
		Iterator operator--(int)
		{
			_Elem = _Elem->_Prev;
			return this;
		}
		Iterator& operator++()
		{
			_Elem = _Elem->_Next;			
			return *this;
		}
		Iterator& operator--()
		{
			_Elem = _Elem->_Prev;
			return *this;
		}
		friend bool operator==(const Iterator& e1, const Iterator& e2)
		{ 
			return e1._Elem == e2._Elem;
		}
		friend bool operator!=(const Iterator& e1, const Iterator& e2)
		{
			return e1._Elem != e2._Elem;
		}

	private:
		/// @brief ���ݎw�������Ă��郊�X�g�v�f
		ElemData* _Elem;
	};

	/// @brief ���X�g�̐擪�v�f�̃C�e���[�^���擾����
	/// @return �擪�v�f�̃C�e���[�^
	inline constexpr MyList::Iterator Begin() const { return Iterator(_Front); }
	/// @brief ���X�g�̍Ō���v�f�̃C�e���[�^���擾����
	/// @return �Ō���v�f�̃C�e���[�^
	inline constexpr MyList::Iterator End() const { return Iterator(nullptr); }

private:
	/// @brief �擪�v�f
	ElemData* _Front	= nullptr;
	/// @brief �Ō���v�f
	ElemData* _Back		= nullptr;
	/// @brief �v�f��
	unsigned int _Size	= 0;
};